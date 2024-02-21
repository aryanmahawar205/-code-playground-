/*
The saddle point of a matrix is the element which is minimum to a row and maximum to the column in which it belongs
Eg - 1 2 3
     4 5 6
     7 8 9 is the given matrix, then element 7 is the saddle point

Eg - 2 5 6
     8 4 9
     6 7 3 has no saddle point     
*/

#include <stdio.h>

int main()
{
    int rc;
    printf("Enter the number of rows or columns of the matrix (both are same in this code) - ");
    scanf("%d", &rc);
    int mat[rc][rc];
    printf("\n");
    printf("Enter matrix elements - \n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
    printf("Matrix created as follows - \n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}