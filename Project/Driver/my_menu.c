#include <stdbool.h>
#include <string.h>
#include "stm32f4xx_gpio.h"
#include "my_button.h"
#include "my_led.h"
#include "my_spi.h"
#include "my_usart.h"
#include "my_delay.h"
#include "my_menu.h"

PAGE_TYPE currentPage = MAIN_MENU; // Default

int endIndex = 0;
char currentBuffer[BUFFER_LENGTH] = {0};

bool stopFlag = true; // Flag to stop function

/**
 * Compute an expression and return the result
 */
char* expression_compute (char* expression) {
    return expression;
}

/**
 * Handle led by command line
 */
void command_line_led_handle (char* command) {
    if (false)
		my_usart_send(MY_USART_1, "Wrong command!\r\n");
	else {
		char cmd = command[0];
		char option = command[1];
		int led;
		bool flag;
		
		switch (option) {
		case '1': {
			led = LED_RED;
			break;
			}	
		case '2': {
			led = LED_GREEN;
			break;
			}
		case '3': {
			led = LED_BLUE;
			break;
			}
		case '4': {
			led = LED_ORANGE;
			break;
			}
		case '5': {
			led = LED_RED | LED_GREEN | LED_BLUE | LED_ORANGE;
			break;
			}
		default: {
			my_usart_send(MY_USART_1, "Wrong command!\r\n");
			my_usart_send(MY_USART_1, "Try again:\r\n");
			
			flag = true;
			
			buffer_clear();
			break;
			}						
		}

		if (flag)
			return;
			
		switch (cmd) {
		case '1': {
			my_led_on(led);
			my_usart_send(MY_USART_1, "\r");
			my_usart_send(MY_USART_1, "Your command: ");
			break;
			}
		case '2': {
			my_led_off(led);
			my_usart_send(MY_USART_1, "\r");
			my_usart_send(MY_USART_1, "Your command: ");
			break;
			}
		default: {
			my_usart_send(MY_USART_1, "Wrong command!\r\n");
			my_usart_send(MY_USART_1, "Try again:\r\n");
			
			buffer_clear();
			break;
			}
		}
	}
}

/**
 * Handle menu logic
 */
void menu_logic_handle (void) {
    char buffer[16] = {0};
    unsigned char character;
    bool isTrash;
    switch (currentPage)
    {
        case MAIN_MENU: {
            isTrash = false;
            character = buffer_get();
            switch (character) {
                case '1':
                    currentPage = STUDENT_INFO;
                    break;
                case '2':
                    currentPage = BASIC_OPERATION;
                    break;
                case '3':
                    currentPage = SIMPLE_LED;
                    break;
                case '4':
                    currentPage = ADVANCE_LED;
                    break;
                case '5':
                    currentPage = AUDIO;
                    break;
                case '6':
                    currentPage = ADDITION_FEATURE;
                    break;
                default:
                    isTrash = true;
                break;
            }
            // Clear buffer
            buffer_clear();
            // Show menu
            if (!isTrash) {
                menu_content_handle();
            }
            break;
        }
        case STUDENT_INFO: {
            character = buffer_get();
            // ESC: 27
            if (character == 27) {
                currentPage = MAIN_MENU;
                // Show menu
                menu_content_handle();
            }
            // Clear buffer
            buffer_clear();
            break;
        }
        case BASIC_OPERATION: {
            character = buffer_get();
            if (character == 27) { // ESC: 27
                currentPage = MAIN_MENU;
                menu_content_handle();
                // Clear buffer
                buffer_clear();
            } else if (character == 13) { // Enter: 13
                my_usart_send(MY_USART_1, "\r\nResult: ");
                my_usart_send(MY_USART_1, expression_compute(currentBuffer));
                my_usart_send(MY_USART_1, "\r\n\r\n");
                // Clear buffer
                buffer_clear();
            } else if ((character >= 40 && character <= 43) ||
                        (character >= 45 && character <= 47) ||
                        (character >= 48 && character <= 57) ||
                        (character == 37)) {

                buffer[0] = character;
                my_usart_send(MY_USART_1, buffer);
            } else if (character == 8) {
                buffer_pop(); // Backspace
                buffer_pop();
                my_usart_send(MY_USART_1, "\b \b");
            } else {
                buffer_pop();
            }
            break;
        }
        case SIMPLE_LED: {
            character = buffer_get();
            if (character == 27) { // ESC: 27
                currentPage = MAIN_MENU;
                menu_content_handle();
                // Clear buffer
                buffer_clear();
                // Stop
                stopFlag = true;
            } else if (character == 13) { // Enter: 13
                my_usart_send(MY_USART_1, "\r\n");
                command_line_led_handle(currentBuffer);
                // Clear buffer
                buffer_clear();
            } else if (character >= 33 && character <= 126) {
                buffer[0] = character;
                my_usart_send(MY_USART_1, buffer);
            } else if (character == 8) {
                buffer_pop(); // Backspace
                buffer_pop();
                my_usart_send(MY_USART_1, "\b \b");
            } else {
                buffer_pop();
            }
            break;
        }
        case ADVANCE_LED: {
            isTrash = false;
            character = buffer_get();
            switch (character) {
                case '1':
                    currentPage = ADVANCE_LED_SET_LED;
                    break;
                case '2':
                    currentPage = ADVANCE_LED_SET_DIRECTION;
                    break;
                case '3':
                    currentPage = ADVANCE_LED_START;
                    break;
                default:
                    isTrash = true;
                break;
            }
            // Clear buffer
            buffer_clear();
            // Show menu
            if (!isTrash) {
                menu_content_handle();
            }
            break;
        }
        case ADVANCE_LED_SET_LED: {
            break;
        }
        case ADVANCE_LED_SET_DIRECTION: {
            break;
        }
        case ADVANCE_LED_START: {
            break;
        }
        case AUDIO: {
            character = buffer_get();
            if (character == 27) { // ESC: 27
                currentPage = MAIN_MENU;
                // Show menu
                menu_content_handle();
            }
            // Clear buffer
            buffer_clear();
            break;
        }
        case ADDITION_FEATURE: {
            break;
        }
    }
}

/**
 * Handle menu content
 */
void menu_content_handle (void) {
    // Clear terminal screen
    terminal_clear();
    switch (currentPage)
    {
        case MAIN_MENU: {
            my_usart_send(MY_USART_1, "***** FINAL PROJECT *****\r\n");
            my_usart_send(MY_USART_1, "Choose your option (1, 2, ...):\r\n");
            my_usart_send(MY_USART_1, "1. Student info.\r\n");
            my_usart_send(MY_USART_1, "2. Basic operation.\r\n");
            my_usart_send(MY_USART_1, "3. Simple LED.\r\n");
            my_usart_send(MY_USART_1, "4. Advance LED.\r\n");
            my_usart_send(MY_USART_1, "5. Audio.\r\n");
            my_usart_send(MY_USART_1, "6. Addition feature.\r\n");
            break;
        }
        case STUDENT_INFO: {
            my_usart_send(MY_USART_1, "***** STUDENT INFO *****\r\n");
            my_usart_send(MY_USART_1, "Member 1:\r\n");
            my_usart_send(MY_USART_1, "Name: Duong Nguyen Anh Khoa\r\n");
            my_usart_send(MY_USART_1, "ID: 1312288\r\n");
            my_usart_send(MY_USART_1, "Email: dnanhkhoa@live.com\r\n");
            my_usart_send(MY_USART_1, "\r\nMember 2:\r\n");
            my_usart_send(MY_USART_1, "Name: Do Dai Thach\r\n");
            my_usart_send(MY_USART_1, "ID: 1312539\r\n");
            my_usart_send(MY_USART_1, "Email: ddthach95@gmail.com\r\n");
            my_usart_send(MY_USART_1, "\r\nESC: Return previous menu.\r\n");
            break;
        }
        case BASIC_OPERATION: {
            my_usart_send(MY_USART_1, "***** BASIC OPERATION *****\r\n");
            my_usart_send(MY_USART_1, "ESC: Return previous menu.\r\n");
            my_usart_send(MY_USART_1, "BACKSPACE: Delete previous character.\r\n");
            my_usart_send(MY_USART_1, "Enter the expression:\r\n");
            break;
        }
        case SIMPLE_LED: {
            my_usart_send(MY_USART_1, "***** SIMPLE_LED *****\r\n");
            my_usart_send(MY_USART_1, "ESC: Return previous menu.\r\n");
            my_usart_send(MY_USART_1, "BACKSPACE: Delete previous character.\r\n");
            my_usart_send(MY_USART_1, "Enter the command: [1.on/ 2.off] [1.r/ 2.g/ 3.b/ 4.o/ 5.all] [ENTER]\r\n");
            my_usart_send(MY_USART_1, "Example on led red: 11\r\n");
			my_usart_send(MY_USART_1, "Your command: ");
			break;
        }
        case ADVANCE_LED: {
            my_usart_send(MY_USART_1, "***** ADVANCE LED *****\r\n");
            my_usart_send(MY_USART_1, "Choose your option (1, 2, 3):\r\n");
            my_usart_send(MY_USART_1, "1. Set LED (Default is Green LED).\r\n");
            my_usart_send(MY_USART_1, "2. Set direction (Default is clockwise).\r\n");
            my_usart_send(MY_USART_1, "3. Start.\r\n");
            my_usart_send(MY_USART_1, "\r\nESC: Return previous menu.\r\n");
            break;
        }
        case ADVANCE_LED_SET_LED: {
            my_usart_send(MY_USART_1, "***** SET LED *****\r\n");
            my_usart_send(MY_USART_1, "ESC: Return previous menu.\r\n");
            my_usart_send(MY_USART_1, "Enter your option (r, g, o, b):\r\n");
            break;
        }
        case ADVANCE_LED_SET_DIRECTION: {
            my_usart_send(MY_USART_1, "***** SET DIRECTION *****\r\n");
            my_usart_send(MY_USART_1, "ESC: Return previous menu.\r\n");
            my_usart_send(MY_USART_1, "Enter your option (c, a):\r\n");
            break;
        }
        case ADVANCE_LED_START: {
            my_usart_send(MY_USART_1, "***** LED IS RUNNING *****\r\n");
            my_usart_send(MY_USART_1, "ESC: Return previous menu.\r\n");
            break;
        }
        case AUDIO: {
            my_usart_send(MY_USART_1, "***** PLAYING AUDIO *****\r\n");
            my_usart_send(MY_USART_1, "ESC: Return previous menu.\r\n");
            break;
        }
        case ADDITION_FEATURE: {
            break;
        }
    }
}

void terminal_clear (void) {
    // ESC + [2J
    my_usart_send(MY_USART_1, "\033[2J");
}

/**
 * Append char to buffer
 */
void buffer_append (char character) {
    if (endIndex < BUFFER_LENGTH - 1) {
        currentBuffer[endIndex] = character;
        endIndex++;
        currentBuffer[endIndex] = 0;
    }
}

/**
 * Pop char from buffer
 */
void buffer_pop (void) {
    if (endIndex > 0) {
        endIndex--;
        currentBuffer[endIndex] = 0;
    }
}

/**
 * Get char from buffer
 */
char buffer_get (void) {
    return endIndex == 0 ? 0 : currentBuffer[endIndex - 1];
}

/**
 * Clear buffer
 */
void buffer_clear(void) {
    endIndex = 0;
    currentBuffer[endIndex] = 0;
}
