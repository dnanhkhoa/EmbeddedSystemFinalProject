#include "stm32f4xx_gpio.h"
#include "my_button.h"
#include "my_spi.h"
#include "my_usart.h"
#include "my_menu.h"
#include "my_delay.h"
#include "interrupt_handle.h"

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
}

/**
 * Handle USART3 interrupt
 */
void USART3_IRQHandler (void) {
}

/**
 * Handle USART6 interrupt
 */
void USART6_IRQHandler (void) {
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
