#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_stack.h"

struct My_Node* my_node_create(char chr) {
	struct My_Node* res = (struct My_Node*) malloc(sizeof(struct My_Node));
	
	if (res != NULL) {
		res->_data = chr;
		res->_next = NULL;
	}

	return res;
}

struct My_Stack* my_stack_create(void) {
	struct My_Stack* res = (struct My_Stack*) malloc(sizeof(struct My_Stack));

	if (res != NULL) {
		res->_head = NULL;
		res->_len = 0;
	}

	return res;
}

int my_stack_is_empty(struct My_Stack* myStack) {
	int res = 1;

	if (myStack != NULL) {
		res = (myStack->_head == NULL) ? 1 : 0;
	}

	return res;
}

struct My_Node* my_stack_pop(struct My_Stack* myStack) {
	struct My_Node* res = NULL;

	if (myStack != NULL) {
		if (!my_stack_is_empty(myStack)) {
			res = myStack->_head;
			myStack->_head = res->_next;

			myStack->_len--;
		}
	}

	return res;
}

char* my_stack_pop_s(struct My_Stack* myStack, int x) {
	char* res = (char*) malloc(sizeof(char) * 10);
	int i = 0;

	struct My_Node* tmp = my_stack_top(myStack);
	if (tmp == NULL)
		return NULL;

	// skip space
	do {
		tmp = my_stack_top(myStack);
		if (tmp->_data == ' ')
			myStack->_head = tmp->_next;
		else
			break;
	} while(1);

	do {
		tmp = my_stack_top(myStack);
		if (tmp == NULL || tmp->_data == ' ')
			break;
		else {
			res[i] = tmp->_data;
			myStack->_head = tmp->_next;
			i++;
		}
			
	} while (1);
	
	res[i] = '\0';

	return res;
}

struct My_Node* my_stack_top(struct My_Stack* myStack) {
	return myStack->_head;
}

void my_stack_push(struct My_Stack* myStack, struct My_Node* node) {
	if (node == NULL)
		return;

	if (myStack != NULL) {
		if (my_stack_is_empty(myStack))
			myStack->_head = node;
		else {
			node->_next = myStack->_head;
			myStack->_head = node;
		}

		myStack->_len++;
	}
}

void my_stack_push_s(struct My_Stack* myStack, const char* src) {
	int size = strlen(src);
	int i = size - 1;
	struct My_Node* tmp;	
	
	if (src == NULL || size == 0 || myStack == NULL)
		return;

	for (; i >= 0; i--) {
		tmp = my_node_create(src[i]);
		tmp->_next = myStack->_head;
		myStack->_head = tmp;
	}

	tmp = my_node_create(' ');
	tmp->_next = myStack->_head;
	myStack->_head = tmp;
}
