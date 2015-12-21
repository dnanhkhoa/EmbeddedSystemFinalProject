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

#include "stm32f4xx.h"
#include "my_init.h"
#include "my_menu.h"

/**
 * Entry point
 */
int main(void) {

    // Init system clock
    SystemInit();

    // Init device
    device_init();

    // Draw main menu
    menu_content_handle();

    for (;;) {
        // Loop forever
    }
}
