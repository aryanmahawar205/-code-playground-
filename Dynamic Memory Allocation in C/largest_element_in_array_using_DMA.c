#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, *arr;

    printf("\nEnter the size of the array you wish to create - ");
    scanf("%d", &size);

    arr = (int *)malloc(size*sizeof(int));

    printf("\nEnter elements in the array\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray created as...\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    int max;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i+1])
        {
            max = arr[i];
        }
    }

    printf("\n\nThe maximum element in the array is - %d\n", max);

    free (arr);

    return 0;
}
