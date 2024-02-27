#include <stdio.h>

int main()
{
    int a, b, sum;

    printf("\nEnter the first number - ");
    scanf("%d", &a);

    printf("\nEnter the second number - ");
    scanf("%d", &b);

    int *pointer_a = &a;
    int *pointer_b = &b;
    int *pointer_sum = &sum;

    *pointer_sum = *pointer_a + *pointer_b;

    printf("\nThe sum of these two numbers using pointers is - %d", *pointer_sum);
    printf("\n");
    return 0;
}
