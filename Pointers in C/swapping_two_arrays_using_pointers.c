#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArr, *arr1, *arr2;

    printf("\nEnter the size of the arrays - ");
    scanf("%d", &sizeArr);

    arr1 = (int *)malloc(sizeArr*sizeof(int));
    arr2 = (int *)malloc(sizeArr*sizeof(int));

    printf("\nEnter first array elements...\n");

    for (int i = 0; i < sizeArr; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter second array elements...\n");

    for (int i = 0; i < sizeArr; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("\n\nFirst Array created as...\n\n");

    for (int i = 0; i < sizeArr; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n\nSecond Array created as...\n\n");

    for (int i = 0; i < sizeArr; i++)
    {
        printf("%d ", arr2[i]);
    }

    int *arr1_ptr = arr1;
    int *arr2_ptr = arr2;

    for (int i = 0; i < sizeArr; i++)
    {
        int temp;
        temp = *arr1_ptr;
        *arr1_ptr = *arr2_ptr;
        *arr2_ptr = temp;
        arr1_ptr++;
        arr2_ptr++;
    }

    printf("\n\nFirst Array swapped as...\n\n");

    for (int i = 0; i < sizeArr; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n\nSecond Array swapped as...\n\n");

    for (int i = 0; i < sizeArr; i++)
    {
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);

    return 0;
}
