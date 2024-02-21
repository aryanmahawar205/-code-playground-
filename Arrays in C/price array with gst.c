// to create an array having the price of 3 items which finally prints the price with 18% GST

#include <stdio.h>

int main()
{
    float price[3];
    for (int i = 0; i <= 2; i++)
    {
        printf("Enter the price of the item - ");
        scanf("%f", &price[i]);
    }
    for (int i = 0; i <= 2; i++)
    {
        printf("The elements of the array with the GST price is - %f \t", price[i]+0.18*price[i]);
    }
    return 0;
}