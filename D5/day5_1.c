#include <stdio.h>
#include <stdlib.h>



#define STACK_SIZE 10

typedef struct stack
{
    char stack[STACK_SIZE];
    short int stack_level;
    char (*pop) (struct stack *stack_value);
    char (*push) (struct stack *stack_value, char value);
    
}stack;


char pop(stack *stack_value)
{
    char value = stack_value->stack[stack_value->stack_level];
    stack_value->stack[stack_value->stack_level] = 0;
    stack_value->stack_level--;
    return value;
}

char push(stack *stack_value, char value)
{
    stack_value->stack_level++;
    stack_value->stack[stack_value->stack_level] = value;
    return 0;
}

stack *stack_gen()
{
    stack *new_stack = malloc(sizeof(stack));
    new_stack->pop = &pop;
    new_stack->push = &push;
    new_stack->stack_level = -1;

    return new_stack;
}

int main(void)
{


    stack *a = stack_gen();

    a->push(a,'c');
    a->push(a,'d');
    //push(&a,'c');
    push(a,'b');

    printf("%c",pop(a));
    printf("%c",pop(a));
    printf("%c",a->pop(a));

    return 0;
}