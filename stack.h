#ifndef H_STACK
#define H_STACK

#include "graph.h"
#define Stack List

extern Stack *s;

Stack* stack_init();
void push(Stack *element);
Stack* pop();
int stack_IsEmpty();
void stack_free(Stack *stack);

#endif

