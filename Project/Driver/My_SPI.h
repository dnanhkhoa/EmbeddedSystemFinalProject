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
void 	my_spi_init(int SPIx, int mode);
void 	my_spi_send(int SPIx, char* data);
char* 	my_spi_receive(int SPIx);

#endif
