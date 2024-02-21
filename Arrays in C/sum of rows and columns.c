// code to calculate the the sum of elements of each columns and rows

#include <stdio.h>

int main()
{
    int rc, sumRow, sumCol;
    printf("Enter the number of rows or columns (both are same in this code) - ");
    scanf("%d", &rc);
    int mat[rc][rc];
    printf("\n");
    printf("Enter matrix elements - ");
    printf("\n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
    printf("\nMatrix created as - \n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("The sum of each rows are - \n");
    for (int i = 0; i < rc; i++)
    {
        sumRow = 0;
        for (int j = 0; j < rc; j++)
        {
            sumRow += mat[i][j];
        }
        printf("%d", sumRow);
        printf("\n");
    }
    printf("The sum of each columns are - \n");
    for (int i = 0; i < rc; i++)
    {
        sumCol = 0;
        for (int j = 0; j < rc; j++)
        {
            sumCol += mat[j][i];
        }
        printf("%d", sumCol);
        printf("\n");
    }
    return 0;
}