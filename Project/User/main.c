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
#include "interrupt_handle.h"


/** main function
 */
int main(void) {
    
    // Init clock
    SystemInit();
    // Init user button
    my_button_init();
    // Init LED
    my_led_init();

    for (;;) {
        // Do nothing
    }
}
