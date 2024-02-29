#include <stdio.h>

typedef struct bookDetails
{
    char title[100];
    char authorName[100];
    char publication[100];
    int price;

}bk;

int main()
{
    int n;

    printf("\nEnter the number of books whose details you wish store - ");
    scanf("%d", &n);

    bk array[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the title of the book - ");
        scanf("%s", array[i].title);

        printf("Enter the name of the author - ");
        scanf("%s", array[i].authorName);

        printf("Enter the publication of the book - ");
        scanf("%s", array[i].publication);

        printf("Enter the price of the book - ");
        scanf("%d", &array[i].price);
    }

    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nThe book name is - %s", array[i].title);
        printf("\nThe name of the author is - %s", array[i].authorName);
        printf("\nThe publication of the book is - %s", array[i].publication);
        printf("\nThe price of the book is - %d", array[i].price);
        printf("\n");
    }

    printf("\n");

    return 0;
}
