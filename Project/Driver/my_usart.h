/**
 * Test: Passed
 */
#ifndef _MY_USART_H
#define _MY_USART_H

#define MY_USART_1 1
#define MY_USART_2 2
#define MY_USART_3 3
#define MY_USART_6 6

#define DEFAULT_BAUDRATE 9600

/*-------------------------------- Prototype --------------------------------*/
void my_usart_init(uint8_t USARTx);
void my_usart_send(uint8_t USARTx, const char* data);
char my_usart_receive(uint8_t USARTx);

#endif
