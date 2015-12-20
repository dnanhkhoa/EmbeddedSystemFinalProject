/**
 * Test: Passed
 */
#include "stm32f4xx_usart.h"
#include "my_gpio.h"
#include "my_usart.h"

/**
 * Init USART
 */
void my_usart_init(uint8_t USARTx) {

    USART_InitTypeDef usart_init;
    NVIC_InitTypeDef nvic_init;

    usart_init.USART_BaudRate               = DEFAULT_BAUDRATE;
    usart_init.USART_HardwareFlowControl    = USART_HardwareFlowControl_None;
    usart_init.USART_Mode                   = USART_Mode_Tx | USART_Mode_Rx;
    usart_init.USART_Parity                 = USART_Parity_No;
    usart_init.USART_StopBits               = USART_StopBits_1;
    usart_init.USART_WordLength             = USART_WordLength_8b;

    nvic_init.NVIC_IRQChannelCmd = ENABLE;
    nvic_init.NVIC_IRQChannelPreemptionPriority = 1;
    nvic_init.NVIC_IRQChannelSubPriority = 0;

    switch (USARTx) {
        case MY_USART_1: {
            my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_6 | GPIO_Pin_7, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
            // Enable clock for USART1 peripheral
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

            // Connect PB6 to USART1_Tx
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);
            // Connect PB7 to USART1_Rx
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

            // Initialize USART1
            USART_Init(USART1, &usart_init);

            // Enable the USART1 receive interrupt
            USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

            nvic_init.NVIC_IRQChannel = USART1_IRQn;
            NVIC_Init(&nvic_init);
            // Activate USART1
            USART_Cmd(USART1, ENABLE);
            break;
        }
        
        case MY_USART_2: {
            my_gpio_init(MY_GPIOA, GPIO_Mode_AF, GPIO_Pin_2 | GPIO_Pin_3, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);

            // Enable clock for USART2 peripheral
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

            // Connect PA2 to USART2_Tx
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
            // Connect PA3 to USART2_Rx
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

            // Initialize USART2
            USART_Init(USART2, &usart_init);

            // Enable the USART2 receive interrupt
            USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

            nvic_init.NVIC_IRQChannel = USART2_IRQn;
            NVIC_Init(&nvic_init);

            // Activate USART2
            USART_Cmd(USART2, ENABLE);
            break;
        }
        
        case MY_USART_3: {
            my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_10 | GPIO_Pin_11, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);

            // Enable clock for USART3 peripheral
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

            // Connect PB10 to USART3_Tx
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
            // Connect PB11 to USART3_Rx
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);

            // Initialize USART3
            USART_Init(USART3, &usart_init);

            // Enable the USART3 receive interrupt
            USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

            nvic_init.NVIC_IRQChannel = USART3_IRQn;
            NVIC_Init(&nvic_init);

            // Activate USART3
            USART_Cmd(USART3, ENABLE);
            break;
        }
        case MY_USART_6: {
            my_gpio_init(MY_GPIOC, GPIO_Mode_AF, GPIO_Pin_6 | GPIO_Pin_7, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);

            // Enable clock for USART6 peripheral
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);

            // Connect PC6 to USART6_Tx
            GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
            // Connect PC7 to USART6_Rx
            GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);

            // Initialize USART6
            USART_Init(USART6, &usart_init);

            // Enable the USART6 receive interrupt
            USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);

            nvic_init.NVIC_IRQChannel = USART6_IRQn;
            NVIC_Init(&nvic_init);

            // Activate USART6
            USART_Cmd(USART6, ENABLE);
            break;
        }
    }
}

/**
 * Send data to USART
 */
void my_usart_send(uint8_t USARTx, const char* data) {       USART_TypeDef* USART = USART6; // Default
    switch (USARTx) {
        case MY_USART_1: {
            USART = USART1;
            break;
        }
        case MY_USART_2: {
            USART = USART2;
            break;
        }
        case MY_USART_3: {
            USART = USART3;
            break;
        }
    }
    while (*data) {
        while (USART_GetFlagStatus(USART, USART_FLAG_TXE) == RESET)
        {
            // Do nothing
        }
        USART_SendData(USART, *data++);
    }
}

/**
 * Get data from USART
 */
char my_usart_receive(uint8_t USARTx) {
    USART_TypeDef* USART = USART6; // Default
    switch (USARTx) {
        case MY_USART_1: {
            USART = USART1;
            break;
        }
        case MY_USART_2: {
            USART = USART2;
            break;
        }
        case MY_USART_3: {
            USART = USART3;
            break;
        }
    }
    while (USART_GetFlagStatus(USART, USART_IT_RXNE) == RESET);
    return (char) USART_ReceiveData(USART);
}
