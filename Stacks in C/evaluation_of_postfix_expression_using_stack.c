#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void push(int x);
int pop();

int s[25] = {0};
int top = -1;

int main()
{
    char postfix[25] = {'\0'};
    char ele;
    int i, num1, num2, ans;

    printf("Enter postfix expression - ");
    scanf("%s", postfix);
    printf("\nPostfix expression entered is - %s", postfix);

    i = 0;

    while (i <= strlen(postfix)-1)
    {
        ele = postfix[i];

        if (isdigit(ele))
            push(ele - '0');

        else
        {
            num1 = pop();
            num2 = pop();

            switch(ele)
            {
                case '^':
                    ans = pow(num2, num1);
                    break;
                case '/':
                    ans = num2/num1;
                    break;
                case '*':
                    ans = num2*num1;
                    break;
                case '+':
                    ans = num2+num1;
                    break;
                case '-':
                    ans = num2-num1;
                    break;
                default:
                    printf("\nInvalid operator %c", ele);
                    break;
            }
            push(ans);
        }
        i++;
    }

    printf("\nResult - %d", pop());

    return 0;
}

void push(int x)
{
    if (top == 24)
        printf("\nStack is full!");

    else
    {
        s[++top] = x;
    }
}

int pop()
{
    if (top == -1)
        printf("\nStack in empty!");

    else
    {
        return s[top--];;
    }
}
