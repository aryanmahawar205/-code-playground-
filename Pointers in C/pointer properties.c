/*
Properties - 

1. We can only subtract one pointer from another. Here pointers should be of the same data type
eg. int *ptr1 = &age1;
    int *ptr2 = &age2;, then ptr2-ptr1 or ptr1-ptr2 only are the valid operations possible

2. We can also compare two pointers (1 -- > True, 0 -- > False)
*/

#include <stdio.h>

int main()
{
    int age = 22;
    int _age = 23;
    int *ptr = &age;
    int *_ptr = &_age;
    printf("Difference = %u \n", ptr-_ptr);
    _ptr = &age;
    printf("Comparison = %u \n", ptr == _ptr);
    return 0;
}