#ifndef _MENU_H
#define _MENU_H

typedef enum {
    MAIN_MENU = 0,
    STUDENT_INFO = 1,
    BASIC_OPERATION = 2,
    SIMPLE_LED = 3,
    ADVANCE_LED = 4,
    AUDIO = 5,
    ADDITION = 6
} PAGE;

/*-------------------------------- Prototype --------------------------------*/
void handle_main_menu();

/*----------------------------- Global variables ----------------------------*/
PAGE current_page;

#endif
