// program to print the factorial of a number

int main()
{
    int num;
    printf("Enter the number whose factorial you wish to calculate - ");
    scanf("%d", &num);

    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    printf("Factorial of %d is %d \n", num, fact);

    return 0;
}