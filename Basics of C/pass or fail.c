/*
Student is pass if marks > 30
Student is fail is marks <= 30
*/

#include <stdio.h>

int main()
{
    int marks;
    printf("Enter the marks of the student (0-100) - ");
    scanf("%d", &marks);

    if (marks > 30 && marks <= 100)
    {
        printf("Student has passed!");
    }
    
    else if (marks <= 30 && marks >= 0)
    {
        printf("Student has failed!");
    }

    else
    {
        printf("Invalid marks entered!");
    }
    return 0;
}