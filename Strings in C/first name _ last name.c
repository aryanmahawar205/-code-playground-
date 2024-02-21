// code to print first name and last name using strings in c

#include <stdio.h>

void printString(char arr[]); // note here we do not pass the size of the string, it it known to the compiler that the string ends at '\0' only

int main()
{
    char firstName[] = "Aryan";
    char lastName[] = "Mahawar";
    printString(firstName);
    printString(lastName);
    return 0;
}

void printString(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}