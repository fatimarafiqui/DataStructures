#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int capacity;
    char* array;
};

struct stack* createstack (int capacity)
{
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top = -1;
    stack-> capacity = capacity;
    stack-> array = (char*)malloc(stack->capacity * sizeof(char*));
    return stack;
}
int isFULL(struct stack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEMPTY(struct stack* stack)
{    
    return stack->top == -1;
}

void push(struct stack* stack, char item)
{
    if(isFULL(stack))
        return;
    stack->array[++stack->top] = item;
    return;
}

char  pop(struct stack* stack)
{
    if(!isEMPTY(stack))
        return stack->array[stack->top--];
}

void reversestr(char str[])
{
    int n = strlen(str);
    int i;
    struct stack* stack = createstack(n);
    for(i = 0; i<=n; i++)
        push(stack, str[i]);
    
    for(i = 0; i<=n; i++)
        str[i] = pop(stack);
    printf("\nThe reverse is %s", str);
    return ;
}

int main()
{
    char str[] = "Fatima";
     reversestr(str);
    printf("\nThe reverse is %s", str);
    return 0;
}
