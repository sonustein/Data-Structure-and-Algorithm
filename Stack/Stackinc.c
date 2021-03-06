#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
void CreateStack(struct Stack *S, int len)
{
    S->size = len;
    S->top = -1;
    S->arr = (int *)malloc(sizeof(int) * len);
}
int isEmpty(struct Stack *S)
{
    return S->top == -1;
}
void push(struct Stack *S, int data)
{
    if (S->top >= S->size - 1)
    {
        printf("stack overflow\n");
        return;
    }
    S->top++;
    S->arr[S->top] = data;
    printf("%d is pushed\n", data);
}
int pop(struct Stack *S)
{
    int x = INT_MIN;
    if (isEmpty(S))
    {
        printf("stack underflow\n");
        return x;
    }
    x = S->arr[S->top];
    S->top--;
    printf("%d is poped\n", x);
    return x;
}
int main()
{
    struct Stack *stack1 = (struct Stack *)malloc(sizeof(struct Stack));
    CreateStack(stack1, 10);
    for (int i = 0; i <= 10; i++)
    {
        push(stack1, i);
    }

    for (int i = 0; i <= 10; i++)
    {
        pop(stack1);
    }
    return 0;
}