//this code will ask the user for input of a particular number of yards and a particular number of feet
//it is specified in the question that the input of yards and feet has to be a whole number
//the yards and feet have to be passed to a function using pointers which will return the total number of miles as output
//given, 5280 feet = 1 mile and 3 feet = 1 yard

#include <stdio.h>

//function declared to calculate the total miles by accepting pointer inputs to yards and feet
float milesCalculator(int *pointer_to_yards, int *pointer_to_feet);

int main()
{
    int yards, feet;

    printf("\nEnter the number of yards - ");
    scanf("%d", &yards);

    printf("Enter the number of feet - ");
    scanf("%d", &feet);

    int *yards_ptr, *feet_ptr; //declaring integer pointer variables to store memory addresses of yards and feet

    //assigning memory addresses to above declared pointer variables
    yards_ptr = &yards;
    feet_ptr = &feet;
    
    float result; //result stores the actual result in miles returned from the milesCalculator function

    result = milesCalculator(yards_ptr, feet_ptr);

    printf("\nThe total distance is %.2f miles", result);

    printf("\n");

    return 0;
}

//function definition to calculate the total distance in miles
float milesCalculator(int *pointer_to_yards, int *pointer_to_feet)
{
    //yardMiles stores the miles equivalent of yards
    //given in question that 1 yard = 3/5280 miles
    //feetMiles stores the miles equivalent of feet
    //given in question that 1 feet = 1/5280 miles
    
    float yardsMiles, feetMiles, totalMiles;

    yardsMiles = *(pointer_to_yards) * (3.0/5280.0);
    feetMiles = *(pointer_to_feet) * (1.0/5280.0);

    //totalMiles stores the sum of yardMiles and feetMiles which is essentially the result of the program
    totalMiles = yardsMiles + feetMiles;

    //this totalMiles is then returned as output from the function
    return totalMiles;
}