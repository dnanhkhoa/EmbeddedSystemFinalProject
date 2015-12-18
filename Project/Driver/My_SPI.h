#ifndef _SPI_H
#define _SPI_H

#define MODE_MASTER 0
#define MODE_SLAVE	1

#define MY_SPI1 1
#define MY_SPI2 2
#define MY_SPI3 3
#define MY_SPI4 4
#define MY_SPI5 5
#define MY_SPI6 6

/*-------------------------------- Prototype --------------------------------*/
void 	My_SPI_Init(int SPIx, int mode);
void 	My_SPI_SendData(int SPIx, char* data);
char* 	My_SPI_Receive(int SPIx);

#endif
