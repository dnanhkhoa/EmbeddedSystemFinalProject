#include "stm32f4xx_conf.h"
#include "stm32f4xx_spi.h"
#include "my_spi.h"
#include "my_gpio.h"

/** Init SPI
 */
void my_spi_init (int SPIx, int mode) {
	SPI_InitTypeDef		spi_init;
	NVIC_InitTypeDef 	nvic_init;
	
	// Config SPI
	if (mode == MODE_MASTER) {
		spi_init.SPI_Mode = SPI_Mode_Master;
	}
	else {
		spi_init.SPI_Mode = SPI_Mode_Slave;
	}
	spi_init.SPI_CPOL = SPI_CPOL_Low;
	spi_init.SPI_CPHA = SPI_CPHA_2Edge;
	spi_init.SPI_DataSize = SPI_DataSize_8b;
	spi_init.SPI_Direction = SPI_Direction_1Line_Tx;
	spi_init.SPI_FirstBit = SPI_FirstBit_MSB;
	spi_init.SPI_NSS = SPI_NSS_Soft;
	spi_init.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	
	// Config NVIC
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 1;
	nvic_init.NVIC_IRQChannelSubPriority = 1;
	
	// All SPIx uses default Pin pack 1
	switch (SPIx) {
		case MY_SPI1: {
			my_gpio_init(MY_GPIOA, GPIO_Mode_AF, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7
									 , GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
			
			nvic_init.NVIC_IRQChannel = SPI1_IRQn;
			NVIC_Init(&nvic_init);
			SPI_ITConfig(SPI1, SPI_IT_RXNE, ENABLE);
			SPI_ITConfig(SPI1, SPI_IT_TXE, ENABLE);
			
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);

			RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
			
			SPI_Init(SPI1, &spi_init);
			
			SPI_Cmd(SPI1, ENABLE);
			
			break;
		}
		
		case MY_SPI2: {
			my_gpio_init(MY_GPIOC, GPIO_Mode_AF, GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_10
									 , GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
			
			nvic_init.NVIC_IRQChannel = SPI2_IRQn;
			NVIC_Init(&nvic_init);
			SPI_ITConfig(SPI2, SPI_IT_RXNE, ENABLE);
			SPI_ITConfig(SPI2, SPI_IT_TXE, ENABLE);
			
			GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF_SPI2);
			GPIO_PinAFConfig(GPIOC, GPIO_PinSource3, GPIO_AF_SPI2);
			GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI2);

			RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
			
			SPI_Init(SPI2, &spi_init);
			
			SPI_Cmd(SPI2, ENABLE);
			
			break;
		}
		
		case MY_SPI3: {
			my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5
									 , GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
			
			nvic_init.NVIC_IRQChannel = SPI3_IRQn;
			NVIC_Init(&nvic_init);
			SPI_ITConfig(SPI3, SPI_IT_RXNE, ENABLE);
			SPI_ITConfig(SPI3, SPI_IT_TXE, ENABLE);
			
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_SPI3);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI3);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI3);

			RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);
			
			SPI_Init(SPI3, &spi_init);
			
			SPI_Cmd(SPI3, ENABLE);
			
			break;
		}
		
		// No interrupt
		case MY_SPI4: {
			my_gpio_init(MY_GPIOE, GPIO_Mode_AF, GPIO_Pin_2 | GPIO_Pin_5 | GPIO_Pin_6
									 , GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
			
			GPIO_PinAFConfig(GPIOE, GPIO_PinSource2, GPIO_AF_SPI4);
			GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_SPI4);
			GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_SPI4);

			RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI4, ENABLE);
			
			SPI_Init(SPI4, &spi_init);
			
			SPI_Cmd(SPI4, ENABLE);
			
			break;
		}
		
		// No interrupt
		case MY_SPI5: {
			my_gpio_init(MY_GPIOF, GPIO_Mode_AF, GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9
									 , GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
			
			GPIO_PinAFConfig(GPIOF, GPIO_PinSource7, GPIO_AF_SPI5);
			GPIO_PinAFConfig(GPIOF, GPIO_PinSource8, GPIO_AF_SPI5);
			GPIO_PinAFConfig(GPIOF, GPIO_PinSource9, GPIO_AF_SPI5);

			RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI5, ENABLE);
			
			SPI_Init(SPI5, &spi_init);
			
			SPI_Cmd(SPI5, ENABLE);
			
			break;
		}
		
		// No interrupt
		case MY_SPI6: {
			my_gpio_init(MY_GPIOG, GPIO_Mode_AF, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14
									 , GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
			
			GPIO_PinAFConfig(GPIOG, GPIO_PinSource12, GPIO_AF_SPI6);
			GPIO_PinAFConfig(GPIOG, GPIO_PinSource13, GPIO_AF_SPI6);
			GPIO_PinAFConfig(GPIOG, GPIO_PinSource14, GPIO_AF_SPI6);

			RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI6, ENABLE);
			
			SPI_Init(SPI6, &spi_init);
			
			SPI_Cmd(SPI6, ENABLE);
			
			break;
		}
	}	
}

/** Send data through SPI
 */
void my_spi_send(int SPIx, char* data) {
	
}

/** Receive data from SPI
 */
char* my_spi_receive(int SPIx) {
	
}
