#include "stm32f4xx_spi.h"
#include "my_gpio.h"
#include "my_spi.h"

/**
 * Init SPI
 */
void my_spi_init (uint8_t SPIx, uint8_t mode) {

    SPI_InitTypeDef     spi_init;
    NVIC_InitTypeDef    nvic_init;

    // Config SPI mode
    if (mode == MODE_MASTER) {
        spi_init.SPI_Mode = SPI_Mode_Master;
        spi_init.SPI_Direction = SPI_Direction_1Line_Tx;
    } else {
        spi_init.SPI_Mode = SPI_Mode_Slave;
        spi_init.SPI_Direction = SPI_Direction_1Line_Rx;
    }

    // Config SPI
    spi_init.SPI_CPOL = SPI_CPOL_High;
    spi_init.SPI_CPHA = SPI_CPHA_1Edge;
    spi_init.SPI_DataSize = SPI_DataSize_8b;
    spi_init.SPI_FirstBit = SPI_FirstBit_MSB;
    spi_init.SPI_NSS = SPI_NSS_Soft;
    spi_init.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;

    // Config NVIC
    nvic_init.NVIC_IRQChannelCmd = ENABLE;
    nvic_init.NVIC_IRQChannelPreemptionPriority = 3;
    nvic_init.NVIC_IRQChannelSubPriority = 0;

    switch (SPIx) {
        case MY_SPI_1: {
            /*
             * PA5 --> SPI1_MOSI
             * PA6 --> SPI1_MISO
             * PA7 --> SPI1_SCK
             * PA4 --> SPI1_SS
             */
            my_gpio_init(MY_GPIOA, GPIO_Mode_AF, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7,
                         GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

            if (mode == MODE_MASTER) {
                my_gpio_init(MY_GPIOA, GPIO_Mode_OUT, GPIO_Pin_4,
                             GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

            } else {
                my_gpio_init(MY_GPIOA, GPIO_Mode_AF, GPIO_Pin_4,
                             GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

                GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_SPI1);
            }

            GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
            
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
            
            // Initialize SPI1
            SPI_Init(SPI1, &spi_init);
            
            // Enable the SPI1 receive interrupt
            SPI_ITConfig(SPI1, SPI_IT_RXNE, ENABLE);

            nvic_init.NVIC_IRQChannel = SPI1_IRQn;
            NVIC_Init(&nvic_init);
            
            // Activate SPI1
            SPI_Cmd(SPI1, ENABLE);
            break;
        }
        
        case MY_SPI_2: {
            /*
             * PB15 --> SPI2_MOSI
             * PB14 --> SPI2_MISO
             * PB13 --> SPI2_SCK
             * PB12 --> SPI2_SS
             */
            my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15,
                         GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

            if (mode == MODE_MASTER) {
                my_gpio_init(MY_GPIOB, GPIO_Mode_OUT, GPIO_Pin_12,
                             GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

            } else {
                my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_12,
                             GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

                GPIO_PinAFConfig(GPIOB, GPIO_PinSource12, GPIO_AF_SPI2);
            }

            GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_SPI2);
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_SPI2);
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI2);
            
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
            
            // Initialize SPI2
            SPI_Init(SPI2, &spi_init);

            // Enable the SPI2 receive interrupt
            SPI_ITConfig(SPI2, SPI_IT_RXNE, ENABLE);

            nvic_init.NVIC_IRQChannel = SPI2_IRQn;
            NVIC_Init(&nvic_init);

            // Activate SPI2
            SPI_Cmd(SPI2, ENABLE);
            break;
        }
        
        case MY_SPI_3: {
            /*
             * PB5 --> SPI3_MOSI
             * PB4 --> SPI3_MISO
             * PB3 --> SPI3_SCK
             * PB6 --> CONTROL_SS
             */
            my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5,
                         GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
            
            if (mode == MODE_MASTER) {
                my_gpio_init(MY_GPIOB, GPIO_Mode_OUT, GPIO_Pin_6,
                             GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

            } else {
                my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_6,
                             GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);

                GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_SPI3);
            }

            GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_SPI3);
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI3);
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI3);
            
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);

            // Initialize SPI3
            SPI_Init(SPI3, &spi_init);

            // Enable the SPI3 receive interrupt
            SPI_ITConfig(SPI3, SPI_IT_RXNE, ENABLE);

            nvic_init.NVIC_IRQChannel = SPI3_IRQn;
            NVIC_Init(&nvic_init);

            // Activate SPI3
            SPI_Cmd(SPI3, ENABLE);
            break;
        }
    }
}

/**
 * Send data through SPI
 */
void my_spi_send(uint8_t SPIx, uint16_t data) {

    GPIO_TypeDef* GPIO = GPIOB;
    uint16_t GPIO_Pin = GPIO_Pin_6;
    SPI_TypeDef* SPI = SPI3;
    
    switch (SPIx) {
        case MY_SPI_1: {
            GPIO = GPIOA;
            GPIO_Pin = GPIO_Pin_4;
            SPI = SPI1;
            break;
        }
        case MY_SPI_2: {
            GPIO = GPIOB;
            GPIO_Pin = GPIO_Pin_12;
            SPI = SPI2;
            break;
        }
    }
    
    while (SPI_GetFlagStatus(SPI, SPI_FLAG_TXE) == RESET)
    {
        // Do nothing
    }
    
    GPIO_ResetBits(GPIO, GPIO_Pin);
    
    SPI_SendData(SPI, data);
    
    GPIO_SetBits(GPIO, GPIO_Pin);
}

/**
 * Receive data from SPI
 */
uint16_t my_spi_receive(uint8_t SPIx) {

    SPI_TypeDef* SPI = SPI3;
    switch (SPIx) {
        case MY_SPI_1: {
            SPI = SPI1;
            break;
        }
        case MY_SPI_2: {
            SPI = SPI2;
            break;
        }
    }

    while (SPI_GetFlagStatus(SPI, SPI_FLAG_RXNE) == RESET)
    {
        // Do nothing
    }
    
    return SPI_ReceiveData(SPI);
}
