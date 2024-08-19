#include <stdio.h>
#include <stdlib.h>

void CountSort(int array[], int size);
void PrintArray(int array[], int size);

int main()
{
    int size; printf("How man elements do you want in your array? - "); scanf("%d", &size);
    int originalArray[size]; printf("Enter the elements - \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &originalArray[i]);
    }

    CountSort(originalArray, size);
    printf("The sorted array is - ");
    PrintArray(originalArray, size);

    return 0;
}

void CountSort(int array[], int size)
{
    // finding maximum element of the original array
    // variable max hold the maximum of the array
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }

    // making the count array which stores the count of each unique element
    // its size will be max+1 = k
    // this count array is also unique on its own since its index numbers are the actual numbers where the values in it correspond to the frequency of each distinct entry in the original array
    // can use DMA for this to save memory space
    // we have to make sure that all the initial entries of the count array are set to 0, hence I used here calloc
    int k = max+1;
    int *count = (int *)calloc(sizeof(int), k);

    // now build the count array to store the frequencies of each unique elements at their respective index locations
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    // now once the base count array is created, we update the count array to store the positions of the elements after sorting
    // this is done by adding the previous element's count to the current element count you're iterator variable is
    // neglect the first (0th) elements obviously, since its position is decided already
    for (int i = 1; i < k; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    // now we allocate space dynamically again, this time using malloc (cause this time around, no need to assign each element initially with 0)
    // the array to be made, say tempArray will be as big as the original size and we arrange it and build it in such a way that it is sorted3
    // refer algorithm in notes, as to how it is carried out
    // just remember to start from the end of the original array (ie, start looping from i=size-1) in order to preserve the stability of the algorithm
    int *tempArray = (int *)malloc(sizeof(int)*size);
    for (int i = size-1; i >= 0; i--)
    {
        tempArray[--count[array[i]]] = array[i];
    }

    // finally copy data (sorted) from tempArray to original array
    for (int i = 0; i < size; i++)
    {
        array[i] = tempArray[i];
    }

    // free the dynamically allocated memory to prevent memory leaks at last
    free(count);
    free(tempArray);
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
