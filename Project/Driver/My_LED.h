/**
 * Test: Passed
 */
#ifndef _MY_LED_H
#define _MY_LED_H

#include "stm32f4xx_gpio.h"

#define LED_GREEN   GPIO_Pin_12
#define LED_ORANGE  GPIO_Pin_13
#define LED_RED     GPIO_Pin_14
#define LED_BLUE    GPIO_Pin_15

/*-------------------------------- Prototype --------------------------------*/
void my_led_init(void);
void my_led_on(uint16_t leds);
void my_led_off(uint16_t leds);

#endif
