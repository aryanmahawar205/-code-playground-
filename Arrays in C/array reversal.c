// code to reverse the array contents
// eg, if the array is 1, 2, 3, 4 ----> 4, 3, 2, 1 is the desired output
// eg, if the array is 1, 2, 3, 4, 5 ----> 5, 4, 3, 2, 1 is the desired output

#include <stdio.h>

void reversal(int arr[], int size);
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
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
    printf("The original array is displayed as above. \n");
    reversal(arr, size);
}

void reversal(int arr[], int size)
{
    int firstValue, secondValue;
    for (int i = 0; i < size/2; i++)
    {
        firstValue = arr[i];
        secondValue = arr[size-i-1];
        arr[i] = secondValue;
        arr[size-i-1] = firstValue;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
    printf("The reversed array is displayed as above. \n");
}