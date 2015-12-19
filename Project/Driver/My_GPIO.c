/**
 * Passed
 */
#include "stm32f4xx_gpio.h"
#include "my_gpio.h"

/**
 * Init GPIO
 */
void my_gpio_init (int GPIOx, GPIOMode_TypeDef mode, int pinx, GPIOOType_TypeDef type
                , GPIOSpeed_TypeDef speed, GPIOPuPd_TypeDef pupd) {

    GPIO_InitTypeDef gpio_init;
    gpio_init.GPIO_Pin = pinx;
    gpio_init.GPIO_Mode = mode;
    gpio_init.GPIO_Speed = speed;
    gpio_init.GPIO_OType = type;
    gpio_init.GPIO_PuPd = pupd;

    // Enable clock
    switch (GPIOx) {
        case MY_GPIOA:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
            GPIO_Init(GPIOA, &gpio_init);
            break;
        
        case MY_GPIOB:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
            GPIO_Init(GPIOB, &gpio_init);             
            break;                                    
                                                      
        case MY_GPIOC:                                
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
            GPIO_Init(GPIOC, &gpio_init);             
            break;                                    
                                                      
        case MY_GPIOD:                                
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
            GPIO_Init(GPIOD, &gpio_init);             
            break;                                    
                                                      
        case MY_GPIOE:                                
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
            GPIO_Init(GPIOE, &gpio_init);             
            break;                                    
                                                      
        case MY_GPIOF:                                
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
            GPIO_Init(GPIOF, &gpio_init);             
            break;                                    
                                                      
        case MY_GPIOG:                                
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
            GPIO_Init(GPIOG, &gpio_init);             
            break;                                    
                                                      
        case MY_GPIOH:                                
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
            GPIO_Init(GPIOH, &gpio_init);             
            break;                                    
                                                      
        case MY_GPIOI:                                
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
            GPIO_Init(GPIOI, &gpio_init);             
            break;                                    
    }
}
