// call by value function to swap two numbers (in actual memory location, the numbers do not get swapped)

#include <stdio.h>

void swap(int a, int b);

int main()
{
    int x = 3, y = 5;
    swap(x, y);
    printf("x = %d, y = %d \n", x, y); // here x = 3, y = 5 (as it is)
    return 0;
}

// call by value
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
    printf("a = %d, b = %d \n", a, b);  // here a = 5 and b = 3 (swapped between a and b)
}


/*
Here after running the code, in the void swap() function, the values of a and b are swapped but no changes are seen in the values of
x and y in the main function. This has happened because we have passed the values of x and y to a and b respectively by creating
their copies viz. the method of pass by value...

always when a variable is passed to a function by value, a copy of it is created in the memory and its lifetime exists only
within the function definition.
*/