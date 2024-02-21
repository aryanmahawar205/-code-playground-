// code to delete a specific value in an already existing array from user specified position

#include <stdio.h>
void creation(int size, int position);
void deletion(int arr[], int size, int position);

int main()
{
    int size, position;
    printf("Enter the size of the parent array you wish to create - ");
    scanf("%d", &size);
    creation(size, position);
    return 0;
}

void creation(int size, int position)
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
    deletion(arr, size, position);
}

void deletion(int arr[], int size, int position)
{
    printf("Enter the position in the parent array whose element you would like to delete - ");
    scanf("%d", &position);
    if (position <= 0 || position > size)
    {
        printf("Invalid position entered, cannot delete element! \n");
    }
    else
    {
        for (int i = position-1; i < size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        
        size -= 1;
        printf("Array after deletion successfully \n");
        for(int i = 0; i < size; i++)
        {
            printf("%d \t", arr[i]);
        }
    }
}