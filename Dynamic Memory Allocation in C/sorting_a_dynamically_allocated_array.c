#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("\nEnter the size of the array you wish to create - ");
    scanf("%d", &size);

    int *array;
    array = (int *)malloc(size*sizeof(int));

    printf("\nEnter array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("\nSorted Array...\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}
