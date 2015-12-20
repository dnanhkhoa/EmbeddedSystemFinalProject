#ifndef _SPI_H
#define _SPI_H

#define MODE_MASTER 0
#define MODE_SLAVE  1

#define MY_SPI_1 1
#define MY_SPI_2 2
#define MY_SPI_3 3

/*-------------------------------- Prototype --------------------------------*/
void my_spi_init(uint8_t SPIx, uint8_t mode);
void my_spi_send(uint8_t SPIx, uint16_t data);
uint16_t my_spi_receive(uint8_t SPIx);

#endif
