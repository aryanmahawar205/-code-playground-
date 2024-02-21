// sum of first n natural numbers

#include <stdio.h>

int sum(int n);

int main()
{
    int n;
    printf("Enter the natural number upto which you want to generate the sum - ");
    scanf("%d", &n);
    printf("The sum is - %d", sum(n));
    return 0;
}

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    int sum_nm1 = sum(n-1);
    int sum_n = sum_nm1 + n;
}