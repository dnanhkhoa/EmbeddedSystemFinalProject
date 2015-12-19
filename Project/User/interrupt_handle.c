#include "my_button.h"
#include "my_led.h"
#include "my_spi.h"
#include "my_usart.h"
#include "my_delay.h"
#include "interrupt_handle.h"

/**
 * Handle user button interrupt
 */
void EXTI0_IRQHandler (void) {
    if (EXTI_GetITStatus(EXTI_Line0) == SET) {
        // Code here
        my_led_on(LED_Blue);
        
        // Clear pending bit in queue
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

/**
 * Handle USART3 interrupt
 */
void USART3_IRQHandler (void) {
    // Handle receive event
    if(USART_GetITStatus(USART3, USART_IT_RXNE)) {
        my_led_on(LED_Green);
    }
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
