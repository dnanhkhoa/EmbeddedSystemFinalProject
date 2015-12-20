#ifndef _MY_MENU_H
#define _MY_MENU_H

typedef enum {
    MAIN_MENU,
    STUDENT_INFO,
    BASIC_OPERATION,
    BASIC_OPERATION_INPUT_EXPRESSION,
    SIMPLE_LED,
    SIMPLE_LED_INPUT_COMMAND,
    ADVANCE_LED,
    ADVANCE_LED_SET_LED,
    ADVANCE_LED_SET_DIRECTION,
    ADVANCE_LED_START,
    AUDIO,
    ADDITION
} PAGE_TYPE;

/*----------------------------- Global variables ----------------------------*/
PAGE_TYPE currentPage = MAIN_MENU;


/*-------------------------------- Prototype --------------------------------*/
void menu_handle();

#endif
