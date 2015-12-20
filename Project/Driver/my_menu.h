#ifndef _MY_MENU_H
#define _MY_MENU_H

#define BUFFER_LENGTH (512 + 1) // 32 chars + 1 NULL

typedef enum {
    MAIN_MENU,
    STUDENT_INFO,
    BASIC_OPERATION,
    SIMPLE_LED,
    ADVANCE_LED,
    ADVANCE_LED_SET_LED,
    ADVANCE_LED_SET_DIRECTION,
    ADVANCE_LED_START,
    AUDIO,
    ADDITION_FEATURE
} PAGE_TYPE;

/*----------------------------- Global variables ----------------------------*/
extern PAGE_TYPE currentPage;

/*-------------------------------- Prototype --------------------------------*/
void command_line_led_handle(char* command);
char* expression_compute(char* expression);

void menu_logic_handle(void);
void menu_content_handle(void);
void terminal_clear(void);
void buffer_append(char character);
void buffer_pop(void);
char buffer_get(void);
void buffer_clear(void);
#endif
