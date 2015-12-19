/**
 * Passed
 */
#include "stm32f4xx_gpio.h"
#include "my_gpio.h"
#include "my_led.h"

/**
 * Config LED
 */
void my_led_init(void) {
    my_gpio_init(MY_GPIOD, GPIO_Mode_OUT, LED_Blue | LED_Green | LED_Red | LED_Orange
                , GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
}

/**
 * Turn on single LED
 */
void my_led_on (LEDS led) {
    GPIO_ResetBits(GPIOD, LED_Blue | LED_Green | LED_Red | LED_Orange);
    GPIO_SetBits(GPIOD, led);
}

/**
 * Turn off single LED
 */
void my_led_off (LEDS led) {
    GPIO_ResetBits(GPIOD, led);
}
