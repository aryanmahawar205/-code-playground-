// code to multiply two matrices

#include <stdio.h>

int main()
{
    int r1, c1, r2, c2;
    printf("Enter the rows of first matrix - ");
    scanf("%d", &r1);
    printf("Enter the columns of first matrix - ");
    scanf("%d", &c1);
    printf("Enter the rows of second matrix - ");
    scanf("%d", &r2);
    printf("Enter the columns of second matrix - ");
    scanf("%d", &c2);
    if (c1 != r2)
    {
        printf("\nMatrices not compatible for multiplication!\n");
    }
    else
    {
        int mat1[r1][c1];
        int mat2[r2][c2];
        int mat3[r1][c2];
        printf("\nEnter the first matrix elements - \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j <c1; j++)
            {
                scanf("%d", &mat1[i][j]);
            }
        }
        printf("\nFirst matrix created as - \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d\t", mat1[i][j]);
            }
            printf("\n");
        }
        printf("\nEnter the second matrix elements - \n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j <c2; j++)
            {
                scanf("%d", &mat2[i][j]);
            }
        }
        printf("\nSecond matrix created as - \n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d\t", mat2[i][j]);
            }
            printf("\n");
        }
        int sum = 0;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < c1; k++)
                {
                    sum += mat1[i][k]*mat2[k][j];
                }
                mat3[i][j] = sum;
                sum = 0;
            }
        }
        printf("\nMultiplied matrix computed as - \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d\t", mat3[i][j]);
            }
            printf("\n");
        }
    }
}