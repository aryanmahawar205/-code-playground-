// program to print the sum of first n natural numbers using the mathematical formula

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n - ");
    scanf("%d", &n);

    int sum;
    sum = n*((n+1)/2);
    printf("Sum is - %d\n", sum);

    return 0;    
}