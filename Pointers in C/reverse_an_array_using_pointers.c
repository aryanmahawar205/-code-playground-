#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("\nEnter the number of elements you wish to have in the array - ");
    scanf("%d", &size);
    printf("\nEnter array elements...\n");

    int *ptr;
    //try below statement without typecasting
    ptr = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("\nArray created as...\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    //performing array reversal without using pointers
    //for (int i = 0; i < size/2; i++)
    //{
        //int temp;
        //temp = ptr[i];
        //ptr[i] = ptr[size-i-1];
        //ptr[size-i-1] = temp;
    //}

    //performing array reversal using pointers
    int *first_value = ptr;
    int *last_value = ptr + size - 1;
    for (int i = 0; i < size/2; i++)
    {
        int temp;
        temp = *first_value;
        *first_value = *last_value;
        *last_value = temp;
        first_value++;
        last_value--;
    }

    printf("\nArray reversed as...\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    return 0;
}
