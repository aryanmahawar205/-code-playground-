// code to insert a specific value in an already existing array at any user specified position

#include <stdio.h>
void creation(int size, int position, int value);
void insertion(int arr[], int size, int position, int value);

int main()
{
    int size, position, value;
    printf("Enter the size of the parent array you wish to create - ");
    scanf("%d", &size);
    creation(size, position, value);
    return 0;
}

void creation(int size, int position, int value)
{
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the parent array element - ");
        scanf("%d", &arr[i]);
    }
    printf("Parent array created with elements \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
    insertion(arr, size, position, value);
}

void insertion(int arr[], int size, int position, int value)
{
    printf("Enter the position in the parent array where you would like to insert the element - ");
    scanf("%d", &position);
    if (position <= 0 || position > size+1)
    {
        printf("Invalid position entered, cannot add element! \n");
    }
    else
    {
        printf("Enter the value you wish to insert - ");
        scanf("%d", &value);
        for (int i = size-1; i >= position-1; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[position-1] = value;
        size += 1;
        printf("Array after insertion successfully \n");
        for(int i = 0; i < size; i++)
        {
            printf("%d \t", arr[i]);
        }
    }
}