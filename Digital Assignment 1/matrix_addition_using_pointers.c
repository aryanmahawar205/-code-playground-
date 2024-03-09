//this code will ask the user for input of 2 two dimensional matrices and display their sum as output
//the sum of the matrices is calculated using pointers

#include <stdio.h>

int rows, cols;

void inputMatrix(int mat[rows][cols]);
void printMatrix(int mat[rows][cols]);
void addMatrix(int mat1[rows][cols], int mat2[rows][cols], int sum[rows][cols]);

int main()
{
    printf("\nEnter the number of rows you wish to have in the matrix - ");
    scanf("%d", &rows);

    printf("Enter the number of columns you wish to have in the matrix - ");
    scanf("%d", &cols);

    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols];

    printf("\nEnter the elements of the first matrix - \n");
    inputMatrix(mat1);

    printf("\nEnter the elements of the second matrix - \n");
    inputMatrix(mat2);

    addMatrix(mat1, mat2, sum);

    printf("\nFirst matrix inputted as - \n");
    printMatrix(mat1);

    printf("\nSecond matrix inputted as - \n");
    printMatrix(mat2);

    printf("\nSum matrix computed as (by using pointers) - \n");
    printMatrix(sum);

    return 0;
}

void inputMatrix(int mat[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void printMatrix(int mat[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

void addMatrix(int mat1[rows][cols], int mat2[rows][cols], int sum[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(sum + i) + j) = *(*(mat1+ i) + j) + *(*(mat2 + i) + j);
        }
    }
}