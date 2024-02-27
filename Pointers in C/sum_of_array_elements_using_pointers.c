#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("\nEnter the size of the array - ");
    scanf("%d", &size);
    printf("\nEnter array elements...\n");

    int *ptr;
    ptr = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("\n\nArray created as...");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    //calculating the sum without using pointers
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ptr[i];
    }
    printf("\n\nSum of array elements without using pointers is - %d", sum);

    //calculating the sum using pointers
    int *sum_ptr = ptr;
    int first_value = *sum_ptr;
    for (int i = 1; i <= size; i++)
    {
        first_value += sum_ptr[i];
    }
    printf("\n\nSum of array elements using pointers is - %d", first_value);
    printf("\n\n");

    free(ptr);

    return 0;
}
