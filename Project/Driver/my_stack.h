#ifndef _MY_STACK_H
#define _MY_STACK_H

struct My_Node {
	char _data;
	struct My_Node* _next;
};

struct My_Stack {
	struct My_Node* _head;
	int _len;
};

struct My_Node* my_node_create(char chr);
struct My_Stack* my_stack_create(void);
int my_stack_is_empty(struct My_Stack* myStack);
struct My_Node* my_stack_pop(struct My_Stack* myStack);
char* my_stack_pop_s(struct My_Stack* myStack, int x);
struct My_Node* my_stack_top(struct My_Stack* myStack);
void my_stack_push(struct My_Stack* myStack, struct My_Node* node);
void my_stack_push_s(struct My_Stack* myStack, const char* src);

#endif
