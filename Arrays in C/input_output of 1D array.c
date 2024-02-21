// basic 1D array creation and displaying its elements

#include <stdio.h>

int main()
{
    int marks[3];
    printf("Enter Maths marks - ");
    scanf("%d", &marks[0]);
    printf("Enter Physics marks - ");
    scanf("%d", &marks[1]);
    printf("Enter Computer marks - ");
    scanf("%d", &marks[2]);
    printf("Maths = %d, Physics = %d, Computer = %d", marks[0], marks[1], marks[2]);
    return 0;
}