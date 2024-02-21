//this code will create an Array of Structures

#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    float cgpa;
    char name[50];
};

int main()
{
    struct student CSE[100];
    CSE[0].roll = 1095;
    CSE[0].cgpa = 9.6;
    strcpy(CSE[0].name, "Aryan");
    printf("The name of the student with %d roll number having %.2f CGPA is %s\n", CSE[0].roll, CSE[0].cgpa, CSE[0].name);
    return 0;
}