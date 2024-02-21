// factorial of a number

#include <stdio.h>

int fact(int n);

int main()
{
    int n;
    printf("Enter the number whose factorial you wish to calculate - ");
    scanf("%d", &n);
    printf("The factorial of the number is %d", fact(n));
    return 0;
}

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    int fact_nm1 = fact(n-1);
    int fact_n = fact_nm1 * n;
}