#ifndef _MY_USART_H
#define _MY_USART_H

#define MY_USART1 1
#define MY_USART2 2
#define MY_USART3 3
#define MY_USART6 6

#define DEFAULT_BAUDRATE 9600

/*-------------------------------- Prototype --------------------------------*/
void my_usart_init(int USARTx);
void my_usart_send(int USARTx, char* data);
char* my_usart_receive(int USARTx);

#endif
