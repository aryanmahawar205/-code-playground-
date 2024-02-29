#include <stdio.h>
#include <string.h>

typedef struct Person
{
   char name[100];
   char date[100];
   int salary;

}per;

int main()
{
    per details[5];

    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter person %d name - ", i+1);
        scanf("%s", details[i].name);

        printf("Enter person %d date of joining - ", i+1);
        scanf("%s", details[i].date);

        printf("Enter the person %d salary - ", i+1);
        scanf("%d", &details[i].salary);
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\nPerson %d name is - %s", i+1, details[i].name);
        printf("\nPerson %d date of joining is - %s", i+1, details[i].date);
        printf("\nPerson %d salary is - %d", i+1, details[i].salary);
        printf("\n");
    }

    return 0;
}
