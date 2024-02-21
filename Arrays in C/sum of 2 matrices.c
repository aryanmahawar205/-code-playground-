// code to add 2 matrices

int main()
{
    int rows, cols;
    printf("Enter the number of rows in the matrix - ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix - ");
    scanf("%d", &cols);
    printf("\n");
    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols];
    printf("Enter the elements of first matrix - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\n");
    printf("Enter the elements of second matrix - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = mat1[i][j] +  mat2[i][j];
        }
    }
    printf("\n");
    printf("\n");
    printf("Matrix one created as follows - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix two created as follows - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Sum matrix computed as follows - \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}