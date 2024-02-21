//this code is just to create a sample structure and figure out how the syntax of it works

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
    struct student s1;
    s1.roll = 1095;
    s1.cgpa = 9.6;
    //s1.name = "Aryan"; this line will give an error because strings are not modifiable in array notation. Hence we use the inbuilt
    //function in strings here to copy the name to s1.name
    strcpy(s1.name, "Aryan");

    printf("Student name is %s\n", s1.name);
    printf("Roll number is %d\n", s1.roll);
    printf("CGPA is %.2f\n", s1.cgpa);
    return 0;
}