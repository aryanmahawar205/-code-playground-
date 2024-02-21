// call by reference function to swap two numbers (in actual memory location, the numbers do get swapped)

#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int x = 3, y = 5;
    swap(&x, &y);
    printf("x = %d, y = %d \n", x, y); // here x = 5, y = 3 (actually swapped)
    return 0;
}

// call by value
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    printf("a = %d, b = %d \n", *a, *b);  // here a = 5 and b = 3 (swapped between a and b)
}


/*
Here after running the code, in the void swap() function, the values of a and b are swapped and changes are seen in the values of
x and y in the main function. This has happened because we have passed the values of x and y to a and b respectively by creating
their actual address references viz. the method of pass by reference...
*/