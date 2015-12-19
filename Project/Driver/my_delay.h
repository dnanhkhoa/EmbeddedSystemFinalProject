#ifndef __MY_DELAY_H
#define __MY_DELAY_H

static volatile int g_systick_counter = 0;

/*-------------------------------- Prototype --------------------------------*/

void systick_init(void);

void systick_delay(volatile int millis);

#endif
