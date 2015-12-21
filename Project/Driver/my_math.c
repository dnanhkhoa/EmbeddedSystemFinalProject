#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_math.h"
#include "my_stack.h"

const char g_my_math_operators[5] = {'%', '*', '/', '+', '-'};

int my_math_is_operator(char chr) {
	int res = 1;
	int i = 0;
	
	for (; i < sizeof(g_my_math_operators) / sizeof(char); i++)
		if (chr == g_my_math_operators[i]) {
			res = 1;
			break;
		}

	return res;
}

int my_math_is_lower_priority(char src, char dest) {
	int res = 0;

	if ((src == '+' || src == '-' || src == BEGIN) && (dest == '*' || dest == '/' || dest == '%'))
		res = 1;

	return res;
}

int my_math_is_digit(char chr) {
	int res = (chr >= 48 && chr <= 57) ? 1 : 0;

	return res;
}

char* my_math_convert(char* src) {
	int i = 0;
	struct My_Stack* res = my_stack_create();
	struct My_Stack* oprt = my_stack_create();
	struct My_Node* temp;
	char* balan = (char*) malloc(res->_len + 1);
	int size;

	for (; i < strlen(src); i++) {
		// digit
		if (my_math_is_digit(src[i])) {
			my_stack_push(res, my_node_create(src[i]));
		}

		// '('
		if (src[i] == '(') {
			my_stack_push(oprt, my_node_create(src[i]));
			my_stack_push(res, my_node_create(' '));
		}
		
		// ')'
		if (src[i] == ')') {
			struct My_Node* tmp;
			my_stack_push(res, my_node_create(' '));

			do {
				tmp = my_stack_top(oprt);
				if (tmp != NULL && tmp->_data != '(') {
					tmp = my_stack_pop(oprt);
					my_stack_push(res, tmp);
				}
				else {
					if (tmp != NULL && tmp->_data == '(')
						my_stack_pop(oprt);

					break;
				}
			} while(1);
		}

		// operators
		if (my_math_is_operator(src[i])) {
			struct My_Node* tmp = my_stack_top(oprt);
			my_stack_push(res, my_node_create(' '));

			if (tmp == NULL)
				my_stack_push(oprt, my_node_create(src[i]));
			else {
				if (my_math_is_lower_priority(src[i], tmp->_data)) {
					do {
						tmp = my_stack_top(oprt);
						if (tmp != NULL && my_math_is_operator(tmp->_data)) {
							tmp = my_stack_pop(oprt);
							my_stack_push(res, tmp);
						}
						else
							break;
					} while (1);

					my_stack_push(res, my_node_create(src[i]));
				}
				else
					my_stack_push(oprt, my_node_create(src[i]));
			}
		}
	}

	// end for
	do {
		temp = my_stack_pop(oprt);
		if (temp != NULL)
			my_stack_push(res, temp);
		else
			break;
	} while (1);

	i = 0;
	size = res->_len;
	temp = res->_head;
	
	while (temp != NULL) {
		balan[size - 1 - i] = temp->_data;
		i++;
		temp = temp->_next;
	}
	balan[size] = '\0';

	return balan;
}

int my_math_format_preprocess(const char* src) {
	int i = 0;
	
	if (src == NULL)
		return 0;

	for (; i < strlen(src); i++) {
		// 2(
		if (my_math_is_digit(src[i])) { 
			if (i < strlen(src) - 1) {
				if (src[i + 1] == '(')
					return 0;
			}
		}

		// 2 3
		if (src[i] == ' ' && i > 0 && i < strlen(src) - 1) { 
			if (my_math_is_digit(src[i - 1]) && my_math_is_digit(src[i + 1]))
				return 0;
		}

		if (src[i] == '(' && i < strlen(src) - 1 && src[i + 1] == ')')
			return 0;
	}

	return 1;
}

/**
 * @src
 * @dest
 * @state
 * @a:	default *srcIndex = 0
 * @b:	default *destIndex = 0
 * @flag:		default flag = false
 */
int my_math_format_process(const char* src, char* dest, int* a, int* b) {
	char lastly = BEGIN;
	
	if (src == NULL || dest == NULL)
		return 0;

	for (; *a < strlen(src); *a += 1) {
		switch (src[*a]) {
		case ' ':
			break;
		
		case '(': {
			if (my_math_is_digit(lastly))
				return 0;
			
			dest[*b] = src[*a];
			*b += 1;
			*a += 1;

			if (!my_math_format_process(src, dest, a, b))
				return 0;

			if (*a == (strlen(src) - 1)) {
				dest[*b] = '\0';
				return 1;
			}

			lastly = dest[*b - 1];

			break;
				  }

		case ')': {
			dest[*b] = src[*a];
			*b += 1;

			return 1;
				  }

		case '*': case '/': case '%': {
			if (my_math_is_lower_priority(lastly, src[*a]))
				return 1;

			dest[*b] = src[*a];
			*b += 1;
			lastly = src[*a];

			break;
				  }

		case '+': case '-': {
			int i = *a;
			char tmp = '+';
			
			// merge sign
			while (src[i] == '+' || src[i] == '-') {
				int check = tmp ^ src[i];
				
				if (check == 0)
					tmp = '+';
				else
					tmp = '-';

				i++;
			}

			*a = i - 1;

			// |-, (-, *-, /-, %-
			if (lastly == '(' || lastly == BEGIN || lastly == '*' || lastly == '/' || lastly == '%') {
				dest[*b] = '(';
				dest[*b + 1] = '0';
				dest[*b + 2] = tmp;
				*b += 3;
				lastly = tmp;

				// get all digits
				while (1) {
					if (src[i] == ' ') {
						i++;
						continue;
					}

					if (i < strlen(src) && my_math_is_digit(src[i])) {
						dest[*b] = src[i];
						lastly = src[i];
						*b += 1;
						i++;
					}
					else {
						if (i < strlen(src) && src[i] == '(') {
							dest[*b] = src[i];
							*b += 1;

							*a = i + 1;
							my_math_format_process(src, dest, a, b);
						}
						else {
							dest[*b] = ')';
							*b += 1;
							*a = i - 1;
						}

						break;
					}
				}
			}
			else {
				dest[*b] = tmp;
				*b += 1;
				lastly = tmp;
			}

			break;
				  }

		default: {
			dest[*b] = src[*a];
			*b += 1;

			if (my_math_is_digit(src[*a]))
				lastly = src[*a];

			break;
				 }
		}
	}

	return 0;
}

char* my_math_format(const char* src) {
	char* dest = NULL;
	int flag;
	int* a = (int*) malloc(sizeof(int));
	int* b = (int*) malloc(sizeof(int));
	
	if (!my_math_format_preprocess(src))
		return dest;

	*a = *b = 0;

	dest = (char*) malloc(sizeof(char) * strlen(src) * 2);
	flag = my_math_format_process(src, dest, a, b);

	if (flag == 0)
		return NULL;
	
	dest[*b] = '\0';

	return dest;
}

char* my_itoa(int x) {
	int i = 0;
	int div, mod;
	int iter = 10;
	char* res = (char*) malloc(sizeof(char) * 10);
	
	if (x < 0) {
		res[i] = '-';
		x = x * -1;
		i++;
	}
	
	while (1) {
		div = x / iter;
		mod = x % iter;
		
		res[i] = mod;
		i++;
		
		if (div == 0)
			break;
		
		iter = iter * 10;
	}
	
	res[i] = '\0';
	
	return res;
}

char* my_math_calculate(const char* src) {
	int size = strlen(src);
	// iter to browse string
	int i = 0;
	
	struct My_Stack* res = my_stack_create();
	char* num = (char*) malloc(sizeof(char) * 10);
	int inum = 0;
	
	if (src == NULL || size == 0)
		return NULL;

	if (src[0] == ' ') {
		while (src[i] == ' ')
			i++;
	}

	for (; i < size; i++) {
		if (my_math_is_digit(src[i])) {
			num[inum] = src[i];
			inum++;
		}
		else {
			num[inum] = '\0';
			inum = 0;
			my_stack_push_s(res, num);

			if (my_math_is_operator(src[i])) {
				int x = atoi(my_stack_pop_s(res, 0));
				int y = atoi(my_stack_pop_s(res, 0));

				switch (src[i]) {
				case '+': {
					
					num = my_itoa(y + x);
					my_stack_push_s(res, num);
					break;
						  }
				case '-': {
					num = my_itoa(y - x);
					my_stack_push_s(res, num);
					break;
						  }
				case '*': {
					num = my_itoa(y * x);
					my_stack_push_s(res, num);
					break;
						  }
				case '/': {
					num = my_itoa(y / x);
					my_stack_push_s(res, num);
					break;
						  }
				case '%': {
					num = my_itoa(y % x);
					my_stack_push_s(res, num);
					break;
						  }
				default:
					break;
				}
			}
		}
	}

	num = my_stack_pop_s(res, 0);

	return num;
}
