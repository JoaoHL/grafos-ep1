#include "stack.h"
#include <stdlib.h>

Stack *s = stack_init();

Stack* stack_init(){
    Stack *x = malloc(sizeof(Stack));
    x->next_stack = NULL;
    return x;
}

void push(Stack *element){
    element->next_stack = s->next_stack;
    s->next_stack = element;
}

Stack* pop(){
    Stack *x = s->next_stack;
    s->next_stack = x->next_stack;
    x->next_stack
    return x;
}

int stack_is_empty(){
    if (s->next_stack == NULL) return 1;
    return 0;
}

void stack_free(Stack *stack){
    free s;
}
