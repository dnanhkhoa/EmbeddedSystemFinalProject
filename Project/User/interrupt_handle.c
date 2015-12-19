#include "interrupt_handle.h"
#include "my_button.h"
#include "my_led.h"
#include "my_spi.h"
#include "my_usart.h"

/** Handle user button interrupt
 */
void EXTI0_IRQHandler(void) {
	if (EXTI_GetITStatus(EXTI_Line0) == SET) {
		my_led_on(LED_Blue);
		
		EXTI_ClearITPendingBit(EXTI_Line0);
	}	
}
