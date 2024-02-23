//this code will take an array which is user defined and return the same array having the odd elements first followed by the even ones

#include <stdio.h>

void reArrange(int numsArr[], int num);  //function to perform the rearrangement

int main()
{
    int num;
    printf("\nEnter the number of integer elements you would wish to have in your array - "); //asking for number of elements in the array
    scanf("%d", &num);
    int numsArr[num]; //creating array of size num
    printf("\nEnter the integer elements to the array\n"); //entering array elements
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &numsArr[i]);
    }
    printf("\nArray created successfully with entries - \n"); //displaying the original array
    for (int i = 0; i < num; i++)
    {
        printf("%d ", numsArr[i]);
    }
    printf("\n");
    reArrange(numsArr, num); //rearrangement function call
    return 0;
}

//rearrangement function definition
void reArrange(int numsArr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = num-1; j > i; j--)
        {
            if (numsArr[i]%2 == 0 && numsArr[j]%2 != 0)
            {
                int temp;
                temp = numsArr[i];
                numsArr[i] = numsArr[j];
                numsArr[j] = temp;
            }
        }
    }
    printf("\nArray rearranged successfully as - \n"); //displaying the rearranged array
    for (int i = 0; i < num; i++)
    {
        printf("%d ", numsArr[i]);
    }
    printf("\n");
}