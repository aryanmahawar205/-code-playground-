//this code will ask the user for input of 2 two dimensional matrices and display their sum as output
//the sum of the matrices is calculated using pointers

#include <stdio.h>

int rows, cols; //declaring global variables for rows and columns to be accessible for all functions below

void inputMatrix(int mat[rows][cols]); //function to take matrix input using pointers
void printMatrix(int mat[rows][cols]); //function to print the matrix using pointers
void addMatrix(int mat1[rows][cols], int mat2[rows][cols], int sum[rows][cols]); //function to add the two matrices using pointers

int main()
{
    printf("\nEnter the number of rows you wish to have in the matrix - ");
    scanf("%d", &rows);

    printf("Enter the number of columns you wish to have in the matrix - ");
    scanf("%d", &cols);

    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols]; //declaring all required matrices

    printf("\nEnter the elements of the first matrix - \n");
    inputMatrix(mat1); //taking input for first matrix elements

    printf("\nEnter the elements of the second matrix - \n");
    inputMatrix(mat2); //taking input for second matrix elements

    addMatrix(mat1, mat2, sum); //computing the addition of the two matrices into matrix sum

    printf("\nFirst matrix inputted as - \n");
    printMatrix(mat1); //printing the first matrix

    printf("\nSecond matrix inputted as - \n");
    printMatrix(mat2); //printing the second matrix

    printf("\nSum matrix computed as (by using pointers) - \n");
    printMatrix(sum); //printing the sum of the two matrices

    return 0;
}

//function definition for taking input of the matrix using pointers
void inputMatrix(int mat[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //the statement &mat[i][j] is equivalent to (*(mat + i) + j)
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
            printf("%d ", *(*(mat + i) + j)); //deference to get the value from the matrix
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
            //deference to get the value from the matrix and store it in sum matrix also by dereferencing
            *(*(sum + i) + j) = *(*(mat1+ i) + j) + *(*(mat2 + i) + j);
        }
    }
}