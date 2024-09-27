#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    struct node *newNode;
    struct node *temp = NULL;
    int choice;

    printf("Do you wish to enter elements into the linked list? (1 for yes, 0 for no) - ");
    scanf("%d", &choice);

    while (choice)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data - ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode; // If list is empty, new node is the head

        else
        {
            temp-> next = newNode; // Otherwise, link the new node
            temp = newNode; // Update temp to point to the new node
        }

        printf("Do you wish to continue adding elements? (1 for yes, 0 for no) - ");
        scanf("%d", &choice);
    }

    // Print the linked list data before insertion, also calculate count (number of elements in LL)
    printf("\nLinked List data before insertion: ");
    temp = head; int count = 0;
    while (temp != NULL)
    {
        count++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    struct node *newBetweenNode; int i = 1; int pos;
    printf("\nEnter the position in the linked list where you wish to add the element - ");
    scanf("%d", &pos);
    if (pos > count)
        printf("Invalid position entered!");
    else
    {
        newBetweenNode = (struct node*)malloc(sizeof(struct node));
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        printf("Enter the value - ");
        scanf("%d", &newBetweenNode->data);
        newBetweenNode->next = temp->next;
        temp->next = newBetweenNode;
    }

    // Print the linked list data after insertion
    printf("\nLinked List data after insertion: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the allocated memory for the linked list
    temp = head;
    while (temp != NULL)
    {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
