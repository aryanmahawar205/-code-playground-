#include <stdio.h>
#include <string.h>

void primeCheck(int *array, int size, int sum);

int main()
{
    int size;
    int sum = 0;

    printf("\nEnter the size of the array you wish to create - ");
    scanf("%d", &size);

    int *array;

    array = (int *)malloc(size*sizeof(int));

    printf("\nEnter the array elements\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nArray created as...\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    primeCheck(array, size, sum);

    free(array);

    return 0;
}

void primeCheck(int *array, int size, int sum)
{
    for (int i = 0; i < size; i++)
    {
        int check = 1;
        for (int j = 2; j <= (array[i])/2; j++)
        {
            if (array[i]%j == 0)
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            sum += array[i];
        }
    }
    printf("\nSum of prime number in the array is %d\n", sum);
}
