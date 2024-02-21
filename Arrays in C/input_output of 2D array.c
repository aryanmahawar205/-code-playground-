// basic creation of 2D array and displaying its elements

#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter the number of rows - ");
    scanf("%d", &rows);
    printf("Enter the number of columns - ");
    scanf("%d", &cols);
    int arr[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter 2D array element - ");
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d \t", arr[i][j]);
        }
    }
    printf("\nArray elements printed above \n");
}