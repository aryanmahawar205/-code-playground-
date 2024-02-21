// pointer arithmetics

#include <stdio.h>

int main()
{
    int age = 22;
    int *ptr = &age;
    printf("Before increment - %u \n", ptr);
    ptr++; // not plus one or minus one, like regular increment or decrement, this here in pointer arithmetic means ek data type se
           // badha do ya ghata do (eg, in this case for int increase by 4 bytes)
    printf("After increment - %u \n", ptr);
    return 0;
}

// similarly as implemented for int, pointer arithmetics could by applied for float and char too as shown below

/*
float price = 20.00;
float *prt = &price;
ptr++; // not plus one or minus one, like regular increment or decrement (again 4 bytes increased for float data type)
*/

/*
char star = '*'
char *ptr = &star;
ptr++; // not plus one or minus one, like regular increment or decrement (here 1 byte increased for char data type)
*/