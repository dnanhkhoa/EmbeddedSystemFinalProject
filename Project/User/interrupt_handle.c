#include "stm32f4xx_gpio.h"
#include "my_button.h"
#include "my_spi.h"
#include "my_usart.h"
#include "my_menu.h"
#include "my_delay.h"
#include "my_led.h"
#include "interrupt_handle.h"
#include <stdio.h>

/**
 * Handle user button interrupt
 */
void EXTI0_IRQHandler (void) {
    if (EXTI_GetITStatus(EXTI_Line0) == SET) {
        // Clear pending bit in queue
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

/**
 * Handle SPI1 interrupt
 */
void SPI1_IRQHandler (void) {
    uint16_t LED;
    char character = my_spi_receive(MY_SPI_1);
    switch (character) {
        case 'g':
            LED = LED_GREEN;
            break;
        case 'o':
            LED = LED_ORANGE;
            break;
        case 'b':
            LED = LED_BLUE;
            break;
        case 'r':
            LED = LED_RED;
            break;
        default:
            my_led_off(LED_BLUE | LED_GREEN | LED_RED | LED_ORANGE);
            return;
    }
    my_led_on(LED);
}

/**
 * Handle USART1 interrupt
 */
void USART1_IRQHandler (void) {
    // Handle receive event
    if(USART_GetITStatus(USART1, USART_IT_RXNE)) {
        char character = my_usart_receive(MY_USART_1);
        buffer_append(character);
        menu_logic_handle();
    }
}

/**
 * Handle USART2 interrupt
 */
void USART2_IRQHandler (void) {
    // Do nothing
}

/**
 * Handle USART3 interrupt
 */
void USART3_IRQHandler (void) {
    // Do nothing
}

/**
 * Handle USART6 interrupt
 */
void USART6_IRQHandler (void) {
    // Do nothing
}

/**
 * Handle SysTick interrupt
 */
void SysTick_Handler (void)
{
    if (g_systick_counter > 0)
    {
        g_systick_counter--;
    }
}
