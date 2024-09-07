#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ReverseExpression(char expression[]);
void push(char x);
char pop();
int priority(char x);

char stack[20];
int top = -1;

int main()
{
    char infix[] = "(A+B)*C-D+F";
    ReverseExpression(infix);
    
    char *exp; char x;
    exp = infix;
    
    char prefix[20] = {'\0'}; int index = 0;
    
    while (*exp != '\0')
    {
        if (isalnum(*exp))
        {
            prefix[index++] = *exp;
        }
        
        else if (*exp == '(')
            push(*exp);
            
        else if (*exp == ')')
        {
            while (top != -1 && (x = pop()) != '(')
                prefix[index++] = x;
        }
        
        else
        {
            while (top != -1 && priority (stack[top]) > priority(*exp))
                prefix[index++] = pop();
            
            push(*exp);
        }
        
        exp++;
    }
    
    while (top != -1)
        prefix[index++] = pop();
        
    ReverseExpression(prefix);
    printf("Prefix Expression: %s", prefix);
    
    return 0;
}

void ReverseExpression(char expression[])
{
    for (int i = 0; i < strlen(expression)/2; i++)
    {
        char firstValue = expression[i];
        char secondValue = expression[strlen(expression)-i-1];
        expression[i] = secondValue;
        expression[strlen(expression)-i-1] = firstValue;
    }
    
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(')
            expression[i] = ')';
        
        else if (expression[i] == ')')
            expression[i] = '(';
    }
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