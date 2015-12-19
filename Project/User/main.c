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

#include "stm32f4xx_conf.h"
#include "my_button.h"
#include "my_led.h"
#include "menu.h"
#include "interrupt_handle.h"

/** main function
 */
int main(void) {
    //handle_main_menu();
    my_button_init();
	my_led_init();
	
	while (1) {
		// do nothing
		
	}
	
	return 0;
}
