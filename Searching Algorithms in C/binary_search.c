#include <stdio.h>

void BinarySearch(int sortedArray[], int size, int target);

int main()
{
    int size; printf("How many elements you wish to have in the array? - "); scanf("%d", &size);
    printf("\nEnter the elements - \n"); int data[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    int target; printf("\nEnter the element which you wish to search for - "); scanf("%d", &target);

    // sorting the data array (USING BUBBLE SORT)
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (data[i] > data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    BinarySearch(data, size, target);

    return 0;
}

void BinarySearch(int sortedArray[], int size, int target)
{
    int left = 0; int right = size-1;
    int found = 0; // set found initially to 0 indicating element not found
    while (left <= right)
    {
        int mid = (left+right)/2;
        if (target == sortedArray[mid])
        {
            printf("Element found at index location %d\n", mid);
            found = 1;
            break;
        }

        else if (target < sortedArray[mid])
        {
            right = mid-1;
        }

        else
        {
            left = mid+1;
        }
    }

    if (found == 0)
    {
        printf("Element not found in the array\n");
    }
}
