#include <stdio.h>

void LinearSearch(int array[], int size, int target);

int main()
{
    int size; printf("How many elements you wish to have in the array? - "); scanf("%d", &size);
    printf("\nEnter the elements - \n"); int data[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    int target; printf("\nEnter the element which you wish to search for - "); scanf("%d", &target);

    LinearSearch(data, size, target);

    return 0;
}

void LinearSearch(int array[], int size, int target)
{
    int found = 0; // initialize found to 0, which means target element not found
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            printf("Element found at index location %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Element not found in the array\n");
    }
}
