#include "stm32f4_discovery.h"
#include "my_delay.h"

/**
 * Init SysTick
 */
void systick_init (void)
{
    RCC_ClocksTypeDef rcc_clocks;
    RCC_GetClocksFreq(&rcc_clocks);
    
    // SystemFrequency / 1000 -> 1ms
    while (SysTick_Config(rcc_clocks.HCLK_Frequency / 1000))
    {
        // Do nothing
    }
    
    // Set 4 bits for preemption, 0 bits for sub priority
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    // Set SysTick interrupt priority, 0 is the highest for all
    NVIC_SetPriority(SysTick_IRQn, 0);
}

/**
 * Suspend execution of a program for a particular time
 */
void systick_delay (volatile int millis)
{
    g_systick_counter = millis;
    while (g_systick_counter)
    {
        // Do nothing
    }
}
