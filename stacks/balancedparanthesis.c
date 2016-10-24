#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_stack
{
    int top;
    int capacity;
    char* array;
};

struct s_stack* createstack (int capacity)
{
    struct s_stack* stack = (struct s_stack*)malloc(sizeof(struct s_stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFULL(struct s_stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEMPTY(struct s_stack* stack)
{    
    return stack->top == -1;
}

void push(struct s_stack* stack, char item)
{
    if(isFULL(stack))
        return;
    stack->array[++stack->top] = item;
}

void pop(struct s_stack* stack)
{
    if(!isEMPTY(stack))
      stack->array[stack->top] =  stack->array[stack->top--];
}

char peek(struct s_stack* stack)
{
    printf("%c", stack->array[stack->top]);
    return stack->array[stack->top];
}
void displaystack(struct s_stack* stack)
{
    int i = stack->top;
    while(i>=0)
    {
        printf("%d->",stack->array[i]);
        i--;
    }
    return;
}

void balancecheck(char str[])
{
    int n = strlen(str);
    int i;
    struct s_stack* stack = createstack(n);
    for(i = 0; i<n; i++)
    {
        if (str[i] == '(')
        {
            push(stack, str[i]);
            displaystack(stack);
        }
        else if(str[i] == ')')
        {   if(!isEMPTY(stack) && peek(stack) == '(')
                pop(stack);
            else
            { 
               printf("\n%d",peek(stack));
                printf("\nUnbalanced Parenthesis");
            }
        }
    }
    printf("\n%d",peek(stack));
    if (!isEMPTY(stack))
            printf("\nUnbalaced");
}

int main()
{
    char str[] = "())((()))";
    balancecheck(str);
    return 0;
}
