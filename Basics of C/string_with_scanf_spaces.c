#include <stdio.h>

int main()
{
    char buffer[100];
    printf("Enter your string - ");
    scanf("%[^\n]%*c", &buffer);
    printf("Your string is - %s", buffer);
    
    return 0;
}