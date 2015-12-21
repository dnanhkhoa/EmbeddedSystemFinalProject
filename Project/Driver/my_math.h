#ifndef _HEADER_H
#define _HEADER_H

#define BEGIN '|'

int my_math_is_operator(char chr);
int my_math_is_lower_priority(char src, char dest);
int my_math_is_digit(char chr);
char* my_math_convert(char* src);
int my_math_format_preprocess(const char* src);
int my_math_format_process(const char* src, char* dest, int* a, int* b);
char* my_math_format(const char* src);
char* my_math_calculate(const char* src);

#endif
