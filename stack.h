#ifndef H_STACK
#define H_STACK

typedef struct stack {
                        int v;
                        int w;
                        stack *next;
                     } Stack;

Stack *s;

Stack* stack_init();
void push(Stack *stack, int elemento);
int pop(Stack *stack);
int stack_free(Stack* stack);

#endif

