#include <stdio.h>

/*
Unions in C are very similar to structures. They also create what is called as user-defined data types.
The difference lies in the point that in the case of Unions space in memory is assigned for the largest
sized member of the union.
Say you assign two members to a structure, an integer (4 bytes) and a character array of 10 characters (10 bytes)
Now if you do some assignment to the integer value and then to the character array and print them out both, the
latest operation only retained ... viz. you will get some random garbage value at the integer and only the
character array will remain as assigned.
On the flip side, say you first do assignment to the character array and then to the integer. In this case, the
memory for the character array is overwritten and the integer stays alone.
Hence Unions are useful over Structures when we desire only the latest member in the user-defined data type
to stay active and hence also uses up less memory space
*/

union student
{
    int marks;
    float cgpa;
    char name[100]; //largest member of the union, hence 100 bytes is what this union occupies in memory
};

int main()
{
    union student s1;

    s1.marks = 100;
    s1.cgpa = 9.72;
    strcpy(s1.name, "Aryan");

    //in the above three statements the last change to the members is on the character array called name
    //hence only that stays as assigned and everything else becomes garbage

    printf("\nMarks - %d", s1.marks);
    printf("\nCGPA - %f", s1.cgpa);
    printf("\nName - %s", s1.name);

    printf("\n\n-------------------------\n");

    s1.marks = 100;
    strcpy(s1.name, "Aryan");
    s1.cgpa = 9.72;

    //in the above three statements the last change to the members is on the float variable called cgpa
    //hence only that stays as assigned and everything else becomes garbage

    printf("\nMarks - %d", s1.marks);
    printf("\nCGPA - %f", s1.cgpa);
    printf("\nName - %s", s1.name);

    return 0;
}
