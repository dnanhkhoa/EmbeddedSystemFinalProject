#ifndef _MY_LED_H
#define _MY_LED_H

#include "stm32f4xx_gpio.h"

typedef enum {
	LED_Green =	GPIO_Pin_12,
	LED_Blue = GPIO_Pin_13,
	LED_Red = GPIO_Pin_14,
	LED_Orange = GPIO_Pin_15
} LEDS;

/*-------------------------------- Prototype --------------------------------*/
void my_led_on(LEDS led);
void my_led_off(LEDS led);

#endif
