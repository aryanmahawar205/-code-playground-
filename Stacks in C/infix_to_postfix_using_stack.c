#include <stdio.h>
#include <ctype.h>

void push(char x);
char pop();
int priority(char x);

char stack[20];
int top = -1;

int main()
{
    char expression[20];
    char *exp; char x;
    printf("Enter the infix expression - ");
    scanf("%s", expression);
    exp = expression;

    printf("\nPostfix Expression - ");

    while (*exp != '\0')
    {
        if (isalnum(*exp))
            printf("%c", *exp);

        else if (*exp == '(')
            push(*exp);

        else if (*exp == ')')
        {
            while (top != -1 && (x = pop()) != '(')
                printf("%c", x);
        }

        else
        {
            while (top != -1 && priority(stack[top]) >= priority(*exp))
                printf("%c", pop());

            push(*exp);
        }

        exp++;
    }

    while (top != -1)
        printf("%c", pop());

    return 0;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;

    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;

    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;
}
