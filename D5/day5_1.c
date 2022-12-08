#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define STACK_SIZE 10
#define INPUT_SIZE 40
#define MAX_STACK 9

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

stack *stack_generator()
{
    stack *new_stack = malloc(sizeof(stack));
    new_stack->pop = &pop;
    new_stack->push = &push;
    new_stack->stack_level = -1;

    return new_stack;
}

int read_supply(char *file_name,stack *stack_array[])
{
    FILE *file = fopen("d5.txt","r");
    char input[INPUT_SIZE];
    for(int i=0; i<10; i++)
    {
        //fscanf(file,"%[^\n]",input);
        fgets(input,40,file);

        for(int j=0; j<INPUT_SIZE; j++)
        {
            if(input[j] <= 90 && input[j] >= 65)
            {
                stack_array[j/4]->push(stack_array[j/4],input[j]);
            }
        }
        memset(input,0,INPUT_SIZE);
    }

    fclose(file);

    return 0;

}

int reverse_stack(stack *stack_array[])
{
    char temp = 0;
    for(int i=0; i<MAX_STACK; i++)
    {
        for(int j=stack_array[i]->stack_level,k=0; strlen(stack_array[i]->stack)/2 > k; j--,k++)
        {
            temp = stack_array[i]->stack[j];
            stack_array[i]->stack[j] = stack_array[i]->stack[k];
            stack_array[i]->stack[k] = temp;
        }
        
    }
}

int main(void)
{
    stack *stack_array[MAX_STACK];

    for(int i=0; i<MAX_STACK; i++)
    {
        stack_array[i] = stack_generator();
    }

    read_supply("d5.txt",stack_array);
    reverse_stack(stack_array);

    FILE *file = fopen("d5.txt","r");
    while (!feof(file))
    {
        for(int i=0; i<10; i++) fgets(stdout,40,file);

        
    }
    

    return 0;
}