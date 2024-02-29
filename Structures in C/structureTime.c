#include <stdio.h>

typedef struct time_struct
{
    int hours;
    int minutes;
    int seconds;
}time;

int main()
{
    int n;

    printf("\nHow many time formats would you like to display? - ");
    scanf("%d", &n);

    time inputs[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the hours -  ");
        scanf("%d", &inputs[i].hours);
        printf("Enter the minutes -  ");
        scanf("%d", &inputs[i].minutes);
        printf("Enter the seconds -  ");
        scanf("%d", &inputs[i].seconds);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nHours of %d input is %d\n",i+1, inputs[i].hours);
        printf("Minutes of %d input is %d\n",i+1, inputs[i].minutes);
        printf("Seconds of %d input is %d\n",i+1, inputs[i].seconds);
    }
}
