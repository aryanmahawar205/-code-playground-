#include <stdio.h>

void PrintArray(int array[], int size);
int Partition(int array[], int lowerBound, int upperBound);
void QuickSort(int array[], int lowerBound, int upperBound);

int main()
{
    int size; printf("How many elements you wish to have in the array - "); scanf("%d", &size);
    int data[size];

    printf("\nEnter the elements - \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    int lower = 0; int upper = size-1;

    QuickSort(data, lower, upper);
    printf("The array is sorted as follows - ");
    PrintArray(data, size);

    return 0;
}

int Partition(int array[], int lowerBound, int upperBound)
{
    int pivotElement = array[lowerBound];
    int start = lowerBound;
    int end = upperBound;

    while (start < end)
    {
        while (array[start] <= pivotElement)
        {
            start++;
        }

        while (array[end] > pivotElement)
        {
            end--;
        }

        if (start < end)
        {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    // swap pivot (to correct position)
    int temp = array[lowerBound];
    array[lowerBound] = array[end];
    array[end] = temp;

    return end;
}

void QuickSort(int array[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
         int location = Partition(array, lowerBound, upperBound);
         QuickSort(array, lowerBound, location-1); // left partition
         QuickSort(array, location+1, upperBound);
    }
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
