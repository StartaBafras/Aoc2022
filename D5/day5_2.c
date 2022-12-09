#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define STACK_SIZE 200
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

int reverse_some(stack *stack_array[],int value,int array)
{
    char temp = 0;

    for(int i=0; i < value/2; i++)
    {
        temp = stack_array[array]->stack[stack_array[array]->stack_level-i];
        stack_array[array]->stack[stack_array[array]->stack_level-i] = stack_array[array]->stack[stack_array[array]->stack_level+i-value+1];
        stack_array[array]->stack[stack_array[array]->stack_level+i-value+1] = temp;
        
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
    char *temp = malloc(40);
    for(int i=0; i<10; i++) fgets(temp,40,file);
    free(temp);

    int from,to,piece;

    while (!feof(file))
    {
        fscanf(file,"move %d from %d to %d\n",&piece,&from,&to);
        
        for(int i=0; i<piece;i++)
        {
            stack_array[to-1]->push(stack_array[to-1],stack_array[from-1]->pop(stack_array[from-1]));
        }
        reverse_some(stack_array,piece,to-1);
    }


    for(int i=0; i<MAX_STACK;i++)
    {
        printf("%c",stack_array[i]->stack[stack_array[i]->stack_level]);
    }

    return 0;
}