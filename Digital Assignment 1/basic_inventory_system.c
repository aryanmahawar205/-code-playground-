//this code will create a Basic Inventory System for say like a Clothing Retail Store
//the Inventory System can only have a maximum of 15 distinct items
//Each corresponding item in the inventory has 2 values associated with it - its price and the number of items available
//Both these parameters are taken as input from the user
//As an output, the program should calculate the total number of items / pieces in the inventory and total cost of inventory
//Provision to change the values is also to be kept in mind

#include <stdio.h>
#include <string.h>

//defining a custom structure to hold the various parameters of the item in Inventory
typedef struct itemsParameters
{
    char itemName[100];
    int pricePerItem;
    int quantity;
}items;

void inputInventory(items details[], int numberOfItems); //function declared to take input and populate to the Inventory

void correctInventory(items details[], int numberOfItems); //function declared to correct the Inventory quantity to a particular item as mentioned in the problem statement

void displayInventory(items details[], int numberOfItems); //function declared to display the Inventory contents

int main()
{
    int numberOfItems;
    printf("\nEnter the number of items you want to have in the inventory system - ");
    scanf("%d", &numberOfItems);

    //checking if the number of elements in the Inventory are <= 15
    if (numberOfItems > 15)
    {
        printf("\nSorry, Inventory System cannot have more than 15 items!\n");
    }

    else if (numberOfItems <= 15)
    {
        items details[numberOfItems]; //declaring an array of type items as defined in the structure above

        inputInventory(details, numberOfItems); //function call to input the Inventory

        char checker; //check variable to verify if the user wishes to change any of the Inventory quantity for any item

        printf("Do you wish to make changes to any of the items in your inventory system? (y/n) - ");
        scanf(" %c", &checker);

        //this block handles if there is a correction in the Inventory and displays the corrected Inventory
        if (checker == 'y')
        {
            correctInventory(details, numberOfItems); //function call to correct the Inventory quantity
            printf("\n\n----------YOUR INVENTORY DATA IS AS FOLLOWS----------\n");
            displayInventory(details, numberOfItems); //function call to display the Inventory
        }

        //this block displays the Inventory when no correction is to be made in the Inventory
        else if (checker == 'n')
        {
            printf("\n\n----------YOUR INVENTORY DATA IS AS FOLLOWS----------\n");
            displayInventory(details, numberOfItems); //function call to display the Inventory
        }
    }    
    return 0;
}

//function definition to input the contents of the Inventory
void inputInventory(items details[], int numberOfItems)
{
    for (int i = 0; i < numberOfItems; i++)
        {
            printf("\nEnter the name of the item whose inventory you wish to populate - ");
            scanf("%s", details[i].itemName);

            printf("Enter the price per unit of the above said inventory item - ");
            scanf("%d", &details[i].pricePerItem);

            printf("Enter the quantity of the above said inventory item - ");
            scanf("%d", &details[i].quantity);
        }

        printf("\n");
}

//function definition to correct the Inventory quantity of a said item (user - input)
void correctInventory(items details[], int numberOfItems)
{
    char name[100];
    printf("\nEnter the name of the item whose inventory you wish to modify - ");
    scanf("%s", name);

    int isAvailable = 0;

    for (int i = 0; i < numberOfItems; i++)
    {
        if (strcmp(name, details[i].itemName) == 0)
        {
            printf("\nEnter the new quantity of the above said inventory item - ");
            scanf("%d", &details[i].quantity);
            isAvailable = 1;
        }
    }

    if (isAvailable == 0)
    {
        printf("\nSorry, item entered does not exist already in Inventory!");
    }
}

//function definition to print the Inventory contents, such as the total number of items and the total cost
void displayInventory(items details[], int numberOfItems)
{
    int totalPieces = 0;
    int totalCost = 0;

    for (int i = 0; i < numberOfItems; i++)
    {
        totalPieces += details[i].quantity;
        totalCost += details[i].quantity * details[i].pricePerItem;
    }
    printf("\n");
    printf("Total Pieces in Inventory - %d\n", totalPieces);
    printf("Total Cost of all Items - %d\n", totalCost);
}
