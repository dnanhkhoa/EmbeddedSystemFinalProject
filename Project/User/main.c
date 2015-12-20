/**
 * ----- Member 1 -----
 * Name: Dương Nguyễn Anh Khoa
 * ID: 1312288
 * Email: dnanhkhoa@live.com
 
 * ----- Member 2 -----
 * Name: Đỗ Đại Thạch
 * ID: 1312539
 * Email: ddthach95@gmail.com
 */

#include "my_button.h"
#include "my_led.h"
#include "my_usart.h"
#include "my_delay.h"
#include "my_menu.h"

/** main function
 */
int main(void) {

    // Init clock
    SystemInit();

    // Set 4 bits for preemption, 0 bits for sub priority
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

    // Init sytem tick
    systick_init();

    // Init user button
    my_button_init();

    // Init LED
    my_led_init();
    
    // Init USART1
    my_usart_init(MY_USART_1);

    // Draw main menu
    menu_handle();

    for (;;) {
        // Do nothing
    }
}
