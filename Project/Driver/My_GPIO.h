#ifndef _GPIO_H
#define _GPIO_H

#define MY_GPIOA	1
#define MY_GPIOB	2
#define MY_GPIOC	3
#define MY_GPIOD	4
#define MY_GPIOE	5
#define MY_GPIOF	6
#define MY_GPIOG	7
#define MY_GPIOH	8
#define MY_GPIOI	9
#define MY_GPIOJ	10
#define MY_GPIOK	11

/*-------------------------------- Prototype --------------------------------*/
void My_GPIO_Init(int GPIOx, GPIOMode_TypeDef mode, int pinx, GPIOOType_TypeDef type
				  , GPIOSpeed_TypeDef speed, GPIOPuPd_TypeDef pupd);

#endif