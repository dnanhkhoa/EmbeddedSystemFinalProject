/**
 * Test: Passed
 */
#include "stm32f4xx_gpio.h"
#include "my_gpio.h"
#include "my_led.h"

/**
 * Config LED
 */
void my_led_init(void) {
    my_gpio_init(MY_GPIOD, GPIO_Mode_OUT, LED_BLUE | LED_GREEN | LED_RED | LED_ORANGE,
                 GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
}

/**
 * Turn on LEDs
 */
void my_led_on (uint16_t leds) {
    //GPIO_ResetBits(GPIOD, LED_BLUE | LED_GREEN | LED_RED | LED_ORANGE);
    GPIO_SetBits(GPIOD, leds);
}

/**
 * Turn off LEDs
 */
void my_led_off (uint16_t leds) {
    GPIO_ResetBits(GPIOD, leds);
}
