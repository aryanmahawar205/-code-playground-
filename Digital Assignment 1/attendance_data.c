#include <stdio.h>
#include <string.h>

int main()
{
    int num, days;

    printf("\nEnter the number of students from whom you want to store the attendance data - ");
    scanf("%d", &num);

    printf("Enter the number of days for which you want the attendance data - ");
    scanf("%d", &days);

    char data[num][days];

    printf("\nEnter the attendance data - \n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < days; j++)
        {
            scanf(" %c", &data[i][j]);
        }
    }

    printf("\nData entered successfully as - \n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < days; j++)
        {
            printf("%c", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}