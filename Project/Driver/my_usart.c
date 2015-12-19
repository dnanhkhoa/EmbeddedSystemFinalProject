#include "stm32f4xx_conf.h"
#include "stm32f4xx_usart.h"
#include "my_gpio.h"
#include "my_usart.h"

/** Init USART
 */
void my_usart_init(int USARTx) {
	USART_InitTypeDef usart_init;
	NVIC_InitTypeDef nvic_init;
	
	usart_init.USART_BaudRate			    = DEFAULT_BAUDRATE;
	usart_init.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;
	usart_init.USART_Mode					= USART_Mode_Tx | USART_Mode_Rx;
	usart_init.USART_Parity					= USART_Parity_No;
	usart_init.USART_StopBits				= USART_StopBits_1;
	usart_init.USART_WordLength				= USART_WordLength_8b;
	
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 1;
	nvic_init.NVIC_IRQChannelSubPriority = 1;	
	
	// Use default pin pack 1 for all USART
	switch (USARTx) {
		case MY_USART1: {
			my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_6 | GPIO_Pin_7, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);
			
			nvic_init.NVIC_IRQChannel = USART1_IRQn;
			NVIC_Init(&nvic_init);
			USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
			USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
		
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
			
			USART_Init(USART1, &usart_init);
			
			USART_Cmd(USART1, ENABLE);
			
			break;
		}
		
		case MY_USART2: {
			my_gpio_init(MY_GPIOA, GPIO_Mode_AF, GPIO_Pin_2 | GPIO_Pin_3, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
			
			nvic_init.NVIC_IRQChannel = USART2_IRQn;
			NVIC_Init(&nvic_init);
			USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
			USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
		
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
			
			USART_Init(USART2, &usart_init);
			
			USART_Cmd(USART2, ENABLE);
			
			break;
		}
		
		case MY_USART3: {
			my_gpio_init(MY_GPIOB, GPIO_Mode_AF, GPIO_Pin_10 | GPIO_Pin_11, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
			
			nvic_init.NVIC_IRQChannel = USART3_IRQn;
			NVIC_Init(&nvic_init);
			USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
			USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
		
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
			
			USART_Init(USART3, &usart_init);
			
			USART_Cmd(USART3, ENABLE);
			
			break;
		}
		
		// There is no interrupt for USART4, USART5
		
		case MY_USART6: {
			my_gpio_init(MY_GPIOC, GPIO_Mode_AF, GPIO_Pin_6 | GPIO_Pin_7, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
			GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
			GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
			
			nvic_init.NVIC_IRQChannel = USART6_IRQn;
			NVIC_Init(&nvic_init);
			USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
			USART_ITConfig(USART6, USART_IT_TXE, ENABLE);
		
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
			
			USART_Init(USART6, &usart_init);
			
			USART_Cmd(USART6, ENABLE);
			
			break;
		}
	}
}
