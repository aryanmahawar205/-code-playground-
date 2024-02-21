// program to print the sum of first n natural numbers using the for loop

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n - ");
    scanf("%d", &n);
    
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    printf("Sum is - %d \n", sum);
    return 0;    
}