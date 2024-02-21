// namaste bonjour

#include <stdio.h>

void namaste();
void bonjour();

int main()
{
    char ch;
    printf("Enter i for Indian and f for French - ");
    scanf("%c", &ch);
    
    if (ch == 'i')
    {
        namaste();
    }
    else if (ch == 'f')
    {
        bonjour();
    }
    else
    {
        printf("Invalid character inputted! \n");
    }
    
    return 0;
}

void namaste()
{
    printf("Namaste \n");
}

void bonjour()
{
    printf("Bonjour \n");
}