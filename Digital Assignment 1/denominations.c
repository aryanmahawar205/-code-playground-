/*

Rita has a money pouch containing Rs.700. 
There are equal number of 25 paise coins, 50 paise and one rupee coins.
Write a C program to find how many of each are there?

*/

#include <stdio.h>

int main()
{
    float total = 700.00; //total money in rupees with Rita
    float equivalent_25_Paise = 0.25; //in rupees, each 25 paise is of amount 0.25
    float equivalent_50_Paise = 0.50; //in rupees, each 50 paise is of amount 0.50
    float equivalent_1_Rupee = 1.00;

    //say x is the total number of coins of each denomination
    //then, 0.25x + 0.50x + 1.00x = 700.00;
    //therefore, x(0.25 + 0.50 + 1.00) = 700.00
    //hence, x = 700.00/1.75

    //calculating the entire amount which each denomination would contribute
    float denominationsValues_in_Rupees = equivalent_1_Rupee + equivalent_25_Paise + equivalent_50_Paise;

    //the total number of coins would be found out by dividing total amount by denominationsValues_in_Rupees
    printf("\nThere are a total of %.0f coins of each 25 paise, 50 paise and 1 rupee denominations.", total/denominationsValues_in_Rupees);

    printf("\n\n");

    return 0;
}