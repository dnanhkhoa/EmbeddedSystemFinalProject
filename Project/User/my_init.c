/**
 * Test: Passed
 */
#include "stm32f4xx_gpio.h"
#include "my_button.h"
#include "my_led.h"
#include "my_usart.h"
#include "my_spi.h"
#include "my_delay.h"
#include "my_init.h"

void device_init (void) {
    // Set 4 bits for preemption, 0 bits for sub priority
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    
    // Init sytem tick
    systick_init();

    // Init user button
    // my_button_init();

    // Init LED
    my_led_init();

    // Init USART1
    my_usart_init(MY_USART_1);
    
    my_spi_init(MY_SPI_2, MODE_MASTER);

    //my_spi_init(MY_SPI_1, MODE_SLAVE);
}
