#include <stdio.h>

void BubbleSort(int data[], int size);
void PrintArray(int data[], int size);

int main()
{
    int num;
    printf("Enter the number of elements in the array - ");
    scanf("%d", &num);
    int data[num];

    printf("\nEnter the elements - \n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data[i]);
    }

    BubbleSort(data, num);
    printf("The sorted array is - \n");
    PrintArray(data, num);

    return 0;
}

void BubbleSort(int data[], int size)
{
    for (int i = 0; i < (size-1); i++)
    {
        for (int j = 0; j < (size-i-1); j++)
        {
            if (data[j] > data[j+1])
            {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void PrintArray(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}
