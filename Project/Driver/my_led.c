#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "my_led.h"

/** Turn on single LED
 */
void my_led_on (LEDS led) {
	GPIO_ResetBits(GPIOD, LED_Blue | LED_Green | LED_Red | LED_Orange);
	GPIO_SetBits(GPIOD, led);
}

/** Turn off single LED
 */
void my_led_off (LEDS led) {
		GPIO_ResetBits(GPIOD, led);
}
