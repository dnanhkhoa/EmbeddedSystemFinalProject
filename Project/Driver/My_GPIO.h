/**
 * Test: Passed
 */
#ifndef _GPIO_H
#define _GPIO_H

#define MY_GPIOA    1
#define MY_GPIOB    2
#define MY_GPIOC    3
#define MY_GPIOD    4
#define MY_GPIOE    5
#define MY_GPIOF    6
#define MY_GPIOG    7
#define MY_GPIOH    8
#define MY_GPIOI    9

/*-------------------------------- Prototype --------------------------------*/
void my_gpio_init(uint16_t GPIOx, GPIOMode_TypeDef mode, uint16_t pinx, GPIOOType_TypeDef type,
                  GPIOSpeed_TypeDef speed, GPIOPuPd_TypeDef pupd);

#endif
