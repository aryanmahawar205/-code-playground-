// pointer based function pass by reference to perform simple addition, multiplication and average calculation of 2 integers

#include <stdio.h>

void doWork(int a, int b, int *sum, int *mul, int *avg);

int main()
{
    int a = 3, b = 5;
    int sum, mul, avg;
    doWork(a, b, &sum, &mul, &avg);
    printf("Sum = %d, Multiplication = %d, Average = %d \n", sum, mul, avg);
    return 0;
}

void doWork(int a, int b, int *sum, int *mul, int *avg)
{
    *sum = a+b;
    *mul = a*b;
    *avg = (a+b)/2;
}