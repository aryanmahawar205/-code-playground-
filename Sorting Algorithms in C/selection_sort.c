#include <stdio.h>

void SelectionSort(int array[], int size);
void PrintArray(int array[], int size);

int main()
{
    int size; printf("Enter the number of elements you wish to have in the array - ");
    scanf("%d", &size); int data[size]; printf("\nEnter the elements - \n");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    SelectionSort(data, size);

    printf("\nThe array after sorting is - ");

    PrintArray(data, size);

    return 0;
}

void SelectionSort(int array[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int minIndex = i;

        for (int j = i+1; j < size; j++)
        {
            if (array[minIndex] > array[j])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
