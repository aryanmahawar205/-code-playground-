#include <stdio.h>

void PrintArray(int array[], int size);
void InsertionSort(int array[], int size);

int main()
{
    int size; printf("How many elements you wish to have in the array - "); scanf("%d", &size);
    printf("\nEnter the elements - \n"); int data[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("The array after sorting is - ");

    InsertionSort(data, size);
    PrintArray(data, size);

    return 0;
}

void InsertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i-1;

        while (j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
