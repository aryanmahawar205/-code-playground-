/*
say matrix is - 1 2 3 ----- (00) (01) (02)
                4 5 6 ----- (10) (11) (12)
                7 8 9 ----- (20) (21) (22)
now to get the sum of lower triangular elements of the matrix, we logically see that for the lower triangular elements, i>j
(lower triangular elements here are 4, 7 and 8 --> (10), (20) and (21), whose sum is 19) 
*/

#include <stdio.h>

int main()
{
    int rc;
    printf("Enter the number of rows or columns (both are same in this code) - ");
    scanf("%d", &rc);
    int mat[rc][rc];
    printf("\nEnter elements of matrix \n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
    printf("Matrix created as - \n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("The lower triangular elements are - ");
    printf("\n");
    int sum = 0;
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            if (i > j)
            {
                printf("%d\t", mat[i][j]);
                sum += mat[i][j];
            }
        }
    }
    printf("\n");
    printf("The sum of the lower triangular elements is - %d\n", sum);

    return 0;
}