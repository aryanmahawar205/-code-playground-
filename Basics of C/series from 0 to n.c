// program to print the series of numbers from 0 to n, where n is the user input using for loop

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number upto which you wish to print the series of numbers - ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        printf("%d \n", i);
    }

    return 0;
}