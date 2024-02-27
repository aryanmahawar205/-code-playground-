#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int a, b;

    printf("\nEnter the first number - ");
    scanf("%d", &a);

    printf("Enter the second number - ");
    scanf("%d", &b);

    printf("\nBefore swap a = %d and b = %d\n", a, b);

    swap(&a, &b);

    printf("\nAfter swap a = %d and b = %d\n", a, b);

    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
