#ifndef _INTERRUPT_HANDLE_H
#define _INTERRUPT_HANDLE_H

/*-------------------------------- Variables --------------------------------*/
extern volatile int g_systick_counter;

/*-------------------------------- Prototype --------------------------------*/
extern void EXTI0_IRQHandler(void);
extern void USART3_IRQHandler(void);

#endif
