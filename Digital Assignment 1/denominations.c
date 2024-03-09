/*
q11
Rita has a money pouch containing Rs.700. 
There are equal number of 25 paise coins, 50 paise and one rupee coins.
Write a C program to find how many of each are there?

*/

#include <stdio.h>

int main()
{
    int total = 700;
    float equivalent_25_Paise = 0.25; //in rupees
    float equivalent_50_Paise = 0.50; //in rupees
    float equivalent_1_Rupee = 1.00;

    
    // 0.25x + 0.50x + 1x = 700;
    //x(0.25+0.50+1) = 700
    //x = 700/1.75

    float denominationsValues_in_Rupees = equivalent_1_Rupee + equivalent_25_Paise + equivalent_50_Paise;

    printf("\nThere are a total of %.0f coins of each 25 paise, 50 paise and 1 rupee denominations.", total/denominationsValues_in_Rupees);

    printf("\n");

    return 0;
}