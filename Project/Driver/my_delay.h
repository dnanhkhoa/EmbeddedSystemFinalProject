/**
 * Test: Passed
 */
#ifndef __MY_DELAY_H
#define __MY_DELAY_H

extern volatile uint32_t g_systick_counter;

/*-------------------------------- Prototype --------------------------------*/

void systick_init(void);

void systick_delay(volatile uint32_t millis);

#endif
