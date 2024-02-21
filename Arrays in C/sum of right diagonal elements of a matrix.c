/*
say matrix is - 1 2 3 ----- (00) (01) (02)
                4 5 6 ----- (10) (11) (12)
                7 8 9 ----- (20) (21) (22)
(right diagonal elements here are 3, 5 and 7 --> (02), (11) and (20), whose sum is 15) 
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
    printf("The right diagonal elements are - ");
    printf("\n");
    int sum = 0;
    for (int i = 0; i < rc;)
    {
        for (int j = rc-1; j >= 0; j--)
        {
            printf("%d\t",mat[i][j]);
            sum += mat[i][j];
            i++;
        }
    }
    printf("\n");
    printf("The sum of the right diagonal elements is - %d\n", sum);

    return 0;
}