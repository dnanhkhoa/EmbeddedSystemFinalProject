/**
 * Test: Passed
 */
#include "stm32f4xx_exti.h"
#include "my_gpio.h"
#include "my_button.h"

void my_button_init (void) {
    EXTI_InitTypeDef exti_init;
    NVIC_InitTypeDef nvic_init;

    my_gpio_init(MY_GPIOA, GPIO_Mode_IN, GPIO_Pin_0, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_DOWN);
    
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

    exti_init.EXTI_Line = EXTI_Line0;
    exti_init.EXTI_Mode = EXTI_Mode_Interrupt;
    exti_init.EXTI_Trigger = EXTI_Trigger_Rising;
    exti_init.EXTI_LineCmd = ENABLE;
    EXTI_Init(&exti_init);

    nvic_init.NVIC_IRQChannel = EXTI0_IRQn;
    nvic_init.NVIC_IRQChannelCmd = ENABLE;
    nvic_init.NVIC_IRQChannelPreemptionPriority = 2;
    nvic_init.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&nvic_init);
}
