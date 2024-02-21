// program to print a series of numbers from 1 to 10 except for a specific number n

int main()
{
    int n;
    printf("Enter the number you wish to omit from the sequence (1-10) - ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++)
    {   
        if (i == n)
        {
            continue;
        }
        printf("%d \n", i);
    }

    return 0;
}