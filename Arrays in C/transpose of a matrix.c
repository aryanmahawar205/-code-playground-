// code to find the transpose of a matrix and store it in another matrix
// in matrix transpose, rows switch to columns and columns to rows -- which means the order of the matrix also reverses

#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter the number of rows in the original matrix - ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the original matrix - ");
    scanf("%d", &cols);
    int mat1[rows][cols], transpose[cols][rows];
    printf("\n");
    printf("Enter the elements of the original matrix - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\n");
    printf("\n");
    printf("Original matrix created as - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            transpose[j][i] = mat1[j][i];
        }
    }
    printf("\n");
    printf("Transposed matrix created as - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", transpose[j][i]);
        }
        printf("\n");
    }

    return 0;
}