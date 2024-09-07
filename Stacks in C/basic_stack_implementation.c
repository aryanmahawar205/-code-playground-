#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;

void push(stack *st)
{
    int x;
    printf("Enter the data to be pushed into stack - ");
    scanf("%d", &x);

    if (st->top == st->size - 1)
    {
        printf("Overflow condition...cannot insert!\n");
    }

    else
    {
        st->top++;
        st->arr[st->top] = x;
    }
}

void pop(stack *st)
{
    if (st->top == -1)
    {
        printf("Underflow condition...cannot delete!\n");
    }

    else
    {
        st->top--;
    }
}

int top(stack *st)
{
    if (st->top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    else
    {
        return st->arr[st->top];
    }
}

int size(stack *st)
{
    return (st->top) + 1;
}

int main()
{
    // Menu -
    // 1 - to push
    // 2 - to pop
    // 3 - to display top
    // 4 - to display size
    // 5 - to break

    stack *st = (stack*)malloc(sizeof(stack));
    int choice;

    printf("Enter the size of stack - ");
    scanf("%d", &st->size);

    st->arr = (int*)malloc(sizeof(int) * st->size);
    st->top = -1;

    printf("\nEnter your choice -\n"
           "1 - to push\n"
           "2 - to pop\n"
           "3 - to display top\n"
           "4 - to display size\n"
           "5 - to break\n");

    while (1)
    {
        printf("\nChoice - ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push(st);
                break;

            case 2:
                pop(st);
                break;

            case 3:
                printf("Top element is: %d\n", top(st));
                break;

            case 4:
                printf("Current size of stack is: %d\n", size(st));
                break;

            case 5:
                free(st->arr); // Free the allocated memory for array
                free(st);      // Free the allocated memory for stack structure
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
