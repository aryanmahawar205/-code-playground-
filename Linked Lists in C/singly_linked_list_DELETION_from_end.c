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

    // Print the linked list data before deletion from the end
    printf("\nLinked List data before deletion from the end: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    struct node *prevNode;
    if (head == NULL)
        printf("Cannot remove from end, linked list is empty!");
    else{
    temp = head;
    while(temp->next != NULL)
    {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL; free(temp);
    }
    else
    {
        prevNode->next = NULL;
        free(temp);
    }
    }

    // Print the linked list data after deletion from the end
    printf("\nLinked List data after deletion from the end: ");
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
