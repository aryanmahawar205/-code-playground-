#include <stdio.h>

int add(int x, int y)
{
    return x+y;
}

int subtract(int x, int y)
{
    return x-y;
}

int multiply(int x, int y)
{
    return x*y;
}

int divide (int x, int y)
{
    return x/y;
}

int main()
{
    int (*array[4])(int, int);
    array[0] = &add;
    array[1] = &subtract;
    array[2] = &multiply;
    array[3] = &divide;

    int product = (*array[2])(3, 15);

    printf("Product here is : %d\n", product);
    return 0;
}
