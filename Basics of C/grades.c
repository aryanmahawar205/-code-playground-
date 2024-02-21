/*
To give grades to a student, follow the norms
if marks are less than 30, then give a C grade
if marks are more than or equal to 30 and also lesser than 70, then give a B grade
if marks are more than or equal to 70 and and lesser than 90, then give an A grade
if marks are more than or equal to 90 and lesser than and equal to 100, then give A+ grade
*/

#include <stdio.h>

int main()
{
    int marks;
    printf("Enter the marks obtained by the student (0-100) - ");
    scanf("%d", &marks);

    if (marks >= 0 && marks < 30)
    {
        printf("C Grade!");
    }

    else if (marks >= 30 && marks < 70)
    {
        printf("B Grade!");
    }

    else if (marks >= 70 && marks < 90)
    {
        printf("A Grade!");
    }

    else if (marks >= 90 && marks <= 100)
    {
        printf("A+ Grade!");
    }

    else
    {
        printf("Invalid Marks Entered!");
    }

    return 0;
}