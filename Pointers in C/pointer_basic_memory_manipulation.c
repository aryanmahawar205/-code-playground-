#include <stdio.h>

int main()
{
	int array[5];

	printf("    array : %u\n", array);
	printf("array + 1 : %u\n\n", array+1);

	printf("    &array : %u\n", &array);
	printf("&array + 1 : %u\n\n", &array+1);  //incremented by whole array size of 5*4 = 20 bytes

	char a = 'a';
	char b = 'b';

	char *const constant_pointer = &a; //declaring a constant pointer to point to the memory address of variable a
	*constant_pointer = 'x'; //deferencing the contant posinter to another value is possible
	printf("value at contant pointer : %c\n", *constant_pointer);
	//constant_pointer = &b;
	//above is an error statement since a constant pointer can only point to one fixed variable
	//you cannot change it to point it to another variable

	char const *pointer_to_a_constant = &b; //declaring a pointer to a constant to point to the memory address of variable b
	//*pointer_to_a_constant = 'z';
	//above is an error statement since a pointer to a consant value cannot be changed at any time during the program
	//printf("Value at pointer to a constant : %c\n", pointer_to_a_contant); --> should work

	const char *const constant_pointer_to_a_constant = &a;
	//*constant_pointer_to_a_constant = 'S'; //error expected
	//constant_pointer_to_a_constant = &b; //error expected

	return 0;
}
