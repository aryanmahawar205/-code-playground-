#include <stdio.h>

// This same code can be implemented for checking is a given number is odd or even

int main ()
{
    int num ;
    // 1 if the number is divisible by 2
    // 0 if the number is not divisible by 2
    printf("Enter a number - ");
    scanf("%d", &num );
    printf("%d", num%2 == 0);
    return 0;
}