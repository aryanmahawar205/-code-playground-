#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int size;
    printf("\nEnter the size of the array you wish to create - ");
    scanf("%d", &size);

    int *arr;

    arr = (int *)malloc(size*sizeof(int));

    printf("\nEnter the array elements...\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n\nArray created as...\n\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    int elm;

    printf("\n\nEnter the element you wish to search in this array - ");
    scanf("%d", &elm);

    int *arr_ptr = arr;
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (arr_ptr[i] == elm)
        {
            flag = true;
            break;
        }
    }

    if (flag == true)
    {
        printf("\n\nYes, the element %d is present in the array\n", elm);
    }
    else if (flag == false)
    {
        printf("\n\nNo, the element %d is not present in the array\n", elm);
    }

    free(arr);

    return 0;
}
