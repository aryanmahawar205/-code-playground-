// code to calculate and print the odd numbers in an array

#include <stdio.h>

void odd(int arr[], int size);
void creation(int size);

int main()
{
    int size;
    printf("Enter the number of elements in the array - ");
    scanf("%d", &size);
    creation(size);
    return 0;
}    

void creation(int size)
{
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the array element - ");
        scanf("%d", &arr[i]);
    }
    odd(arr, size);
}

void odd(int arr[], int size)
{
    int count_odd = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            count_odd += 1;
            printf("%d \t", arr[i]);
        }
    }
    printf("\n");
    printf("The odd numbers in the array are displayed above with a count of %d \n", count_odd);
}