// code to check is a given matrix is skew symmetric or not
// a matrix is said to be skew symmetric if its transpose equals to  its negative
// for a skew symmetric matrix, the number of rows = number of columns always
// the elements of left diagonal/primary diagonal of a skew symmetric matrix are always equal to 0

#include <stdio.h>

int main()
{
    int rc;
    int flag = 0;
    printf("Enter the number of rows or columns (both are same here in this code) - ");
    scanf("%d", &rc);
    int mat[rc][rc], transpose[rc][rc];
    printf("\n");
    printf("Enter elements of matrix - ");
    printf("\n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
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
    printf("\n");
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            transpose[j][i] = mat[j][i];
        }
    }
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < rc; j++)
        {
            if (transpose[j][i] == -mat[i][j])
            {
                flag = 1;
            }
        }
    }
    if (flag == 1)
    {
        printf("The matrix is skew symmetric.\n");
    }
    else
    {
        printf("The matrix is not skew symmetric.\n");
    }

    return 0;
}