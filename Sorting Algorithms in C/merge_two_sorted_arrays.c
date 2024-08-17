#include <stdio.h>

void MergeArray(int array1[], int size1, int array2[], int size2, int array3[]);
void PrintArray(int array3[], int size);

int main()
{
    int array1[5] = {1, 3, 5, 7, 9};
    int array2[3] = {2, 4, 6};

    int array3[8] = {0}; // array1 and array2 will be merged to array3 in sorted manner

    MergeArray(array1, 5, array2, 3, array3);
    printf("The merged array (sorted) is - \n");
    PrintArray(array3, 8);

    return 0;
}

void MergeArray(int array1[], int size1, int array2[], int size2, int array3[])
{
    int i, j, mergedIndex = 0;

    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
        {
            array3[mergedIndex] = array1[i];
            mergedIndex++; i++;
        }

        else
        {
            array3[mergedIndex] = array2[j];
            mergedIndex++; j++;
        }
    }

    // copy remaining elements from first array (if available)
    while (i < size1)
    {
        array3[mergedIndex] = array1[i];
        mergedIndex++; i++;
    }

    // copy remaining elements from second array (if available)
    while (j < size2)
    {
        array3[mergedIndex] = array2[j];
        mergedIndex++; i++;
    }
}

void PrintArray(int array3[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array3[i]);
    }
}
