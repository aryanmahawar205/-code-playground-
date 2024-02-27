#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("\nEnter the size of the array you wish to create - ");
    scanf("%d", &size);

    int *original, *copy;

    original = (int *)malloc(size*sizeof(int));
    copy = (int *)malloc(size*sizeof(int));

    printf("\nEnter the array elements...\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &original[i]);
    }

    int *original_ptr = original;
    for (int i = 0; i < size; i++)
    {
        copy[i] = *original_ptr;
        original_ptr++;
    }


    printf("\nArray copied as...\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", copy[i]);
    }

    //free(original);
    //free(copy);

    return 0;
}
