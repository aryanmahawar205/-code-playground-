// natural number or not

#include <stdio.h>

int main()
{
    float num;
    printf("Enter any number - ");
    scanf("%f", &num);
    int integer = (int) num;
    
    if (num <= 0)
    {
        printf("Not a natural number! \n");
    }
    else if (num > integer)
    {
        printf("Not a natural number! \n");
    }
    else
    {
        printf("Yes, it is a natural number \n");
    }
}