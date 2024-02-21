// program to print the multiplication table of a number

int main()
{
    int n;
    printf("Enter the number whose multiplication table you wish to generate - ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d \n", n, i, n*i);
    }

    return 0;
}