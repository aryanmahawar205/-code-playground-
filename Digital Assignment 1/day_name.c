//this code will ask the user for an integer number ranging from 1 to 7 and return the corresponding day to it
//by default, here we consider 1 to be Monday (first day of the week)
//the function should return a character pointer to the corresponding day name
//also the day names should be a static character array local to the function

#include <stdio.h>

char* day_name(int number); //character pointer function declared

int main()
{
    int number;

    printf("\nEnter the number (1-7) to the corresponding day you wish to print to the console - ");
    scanf("%d", &number);

    printf("\n");

    char* dayName = day_name(number-1); //function called to get the day name
    printf("%s\n\n", dayName);

    return 0;
}

//function definition of day_name
char* day_name(int number)
{
    //declaring static character array of day names
    static char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    //performing a check if the entered number lies within 1 to 7 and returning the corresponding day name
    if (number >= 0 && number < 7)
    {
        printf("The day corresponding to the number %d is - ", number+1);
        return days[number];
    }
    else
    {
        return "Invalid Day Number!";
    }
}