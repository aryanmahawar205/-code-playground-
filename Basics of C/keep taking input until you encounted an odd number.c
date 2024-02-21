// program using do while loop to keep taking input from the user, until an odd number is entered 

int main()
{
    int n;
    do
    {
        printf("Enter a number - ");
        scanf("%d", &n);
    }
    while (n % 2 == 0);

    return 0;
}