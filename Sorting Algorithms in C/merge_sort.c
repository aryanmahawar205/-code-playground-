#include <stdio.h>
#include <stdlib.h>

void MergeSort(int array[], int start, int end);
void Merge(int array[], int start, int end);
void PrintArray(int array[], int size);

int main()
{
    int array[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int size = 15; int start = 0; int end = size-1;

    MergeSort(array, start, end);
    printf("The sorted array is - \n");
    PrintArray(array, size);

    return 0;
}

void MergeSort(int array[], int start, int end)
{
    // recursion base case
    if (start >= end)
    {
        return;
    }

    int mid = (start+end) / 2;

    // sorting the left half by recursion
    MergeSort(array, start, mid);

    // sorting the right half by recursion
    MergeSort(array, mid+1, end);

    // merging the sorted array
    Merge(array, start, end);

}

void Merge(int array[], int start, int end)
{
    int mid = (start+end) / 2;

    int firstLength = mid-start+1;
    int secondLength = end-mid;

    // make two arrays to copy the values of the original array to merge them in sorted manner
    // using DMA so that I can clear the space borrowed from the heap, once not needed
    int *first = malloc(sizeof(int)*firstLength);
    int *second = malloc(sizeof(int)*secondLength);

    // now copying values
    int mainArrayIndex = start;
    for (int i = 0; i < firstLength; i++)
    {
        first[i] = array[mainArrayIndex];
        mainArrayIndex++;
    }

    mainArrayIndex = mid+1;
    for (int i = 0; i < secondLength; i++)
    {
        second[i] = array[mainArrayIndex];
        mainArrayIndex++;
    }

    // applying the concept of merge two sorted arrays here
    // essentially, each array element (down the recursion tree) in first and second arrays is down to just one single element
    // and one single element is always considered to be sorted be default
    int index1 = 0; int index2 = 0; mainArrayIndex = start;

    while (index1 < firstLength && index2 < secondLength)
    {
        if (first[index1] < second[index2])
        {
            array[mainArrayIndex] = first[index1];
            mainArrayIndex++; index1++;
        }

        else
        {
            array[mainArrayIndex] = second[index2];
            mainArrayIndex++; index2++;
        }
    }

    // copy extra data (if present) from first array
    while (index1 < firstLength)
    {
        array[mainArrayIndex] = first[index1];
        mainArrayIndex++; index1++;
    }

    // copy extra data (if present) from second array
    while (index2 < secondLength)
    {
        array[mainArrayIndex] = second[index2];
        mainArrayIndex++; index2++;
    }

    free(first);
    free(second);
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
