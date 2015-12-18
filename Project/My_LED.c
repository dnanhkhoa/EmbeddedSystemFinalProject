#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "My_LED.h"

/** Turn on single LED
 */
void My_LED_On(LEDS led) {
	GPIO_ResetBits(GPIOD, LED_Blue | LED_Green | LED_Red | LED_Orange);
	GPIO_SetBits(GPIOD, led);
}

/** Turn off single LED
 */
void My_LED_Off(LEDS led) {
		GPIO_ResetBits(GPIOD, led);
}
