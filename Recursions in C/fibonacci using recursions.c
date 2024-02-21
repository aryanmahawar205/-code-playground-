// fibonacci

// 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

#include <stdio.h>

int fib(int n);

int main()
{
    int n;
    printf("Enter the number whose corresponding Fibonacci you wish to generate - ");
    scanf("%d", &n);
    printf("The fibonacci of %d is %d", n, fib(n));
    return 0;
}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
    }
    int fib_nm1 = fib(n-1);
    int fib_nm2 = fib(n-2);
    int fib_n = fib_nm1 + fib_nm2;
}