//this code will create a Basic Inventory System for say like a Clothing Retail Store
//the Inventory System can only have a maximum of 15 distinct items
//Each corresponding item in the inventory has 2 values associated with it - its price and the number of items available
//Both these parameters are taken as input from the user
//As an output, the program should calculate the total number of items / pieces in the inventory and total cost of inventory
//Provision to change the values is also to be kept in mind

#include <stdio.h>
#include <string.h>

typedef struct itemsParameters
{
    char itemName[100];
    int pricePerItem;
    int quantity;
}items;

void inputInventory(items details[], int numberOfItems);

void correctInventory(items details[], int numberOfItems);

void displayInventory(items details[], int numberOfItems);

int main()
{
    int numberOfItems;
    printf("Enter the number of items you want to have in the inventory system - ");
    scanf("%d", &numberOfItems);

    if (numberOfItems > 15)
    {
        printf("Inventory System cannot have more than 15 items!");
    }

    else if (numberOfItems <= 15)
    {
        items details[numberOfItems];

        inputInventory(details, numberOfItems);

        char checker;

        printf("Do you wish to make changes to any of the items in your inventory system? (y/n) - ");
        scanf(" %c", &checker);

        if (checker == 'y')
        {
            correctInventory(details, numberOfItems);
            displayInventory(details, numberOfItems);
        }

        else if (checker == 'n')
        {
            displayInventory(details, numberOfItems);
        }
    }    
    return 0;
}

void inputInventory(items details[], int numberOfItems)
{
    for (int i = 0; i < numberOfItems; i++)
        {
            printf("\nEnter the name of the item whose inventory you wish to populate - ");
            scanf("%s", details[i].itemName);

            printf("\nEnter the price per unit of the above said inventory item - ");
            scanf("%d", &details[i].pricePerItem);

            printf("\nEnter the quantity of the above said inventory item - ");
            scanf("%d", &details[i].quantity);
        }

        printf("\n\n");
}

void correctInventory(items details[], int numberOfItems)
{
    char name[100];
    printf("Enter the name of the item whose inventory you wish to modify - ");
    scanf("%s", name);

    for (int i = 0; i < numberOfItems; i++)
    {
        if (strcmp(name, details[i].itemName) == 0)
        {
            printf("\nEnter the new price per unit of the above said inventory item - ");
            scanf("%d", &details[i].pricePerItem);

            printf("\nEnter the new quantity of the above said inventory item - ");
            scanf("%d", &details[i].quantity);
        }
    }
}

void displayInventory(items details[], int numberOfItems)
{
    int totalPieces = 0;
    int totalCost = 0;

    for (int i = 0; i < numberOfItems; i++)
        {
            totalPieces += details[i].quantity;
            totalCost += details[i].quantity * details[i].pricePerItem;
        }

        printf("Total Pieces - %d\n", totalPieces);
        printf("Total Cost - %d\n", totalCost);
}
