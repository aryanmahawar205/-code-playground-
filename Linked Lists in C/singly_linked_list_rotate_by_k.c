// Rotate a Linked List by K

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createLinkedList(struct node **head, int num);
void printLinkedList(struct node **head);
void freeLinkedListMemory(struct node **head);
void rotateLinkedList(struct node **head, int k);


int main()
{
    struct node *head = NULL;
    int num; printf("Enter the number of elements you wish to have in the linked list - "); scanf("%d", &num);
    printf("\n");
    createLinkedList(&head, num);
    printf("\nLinked list data: ");
    printLinkedList(&head);
    
    int k; printf("\n\nEnter the number by which you want to rotate the linked list - "); scanf("%d", &k);
    printf("\nLinked list data after rotation: ");
    rotateLinkedList(&head, k);
    printLinkedList(&head);
    
    return 0;
}

void createLinkedList(struct node **head, int num)
{
    struct node *temp = NULL; struct node *newNode;

    while(num != 0)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data - ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (*head == NULL)
            *head = temp = newNode;

        else
        {
            temp->next = newNode;
            temp = newNode;
        }

        num--;
    }
}

void printLinkedList(struct node **head)
{
    struct node *temp = NULL;
    temp = *head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void freeLinkedListMemory(struct node **head)
{
    struct node *temp = NULL;
    temp = *head;
    while(temp != NULL)
    {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

void rotateLinkedList(struct node **head, int k)
{
    if (*head == NULL || k == 0) return; // No rotation needed

    // Calculate the length of the linked list
    struct node *temp = *head;
    int count = 1; // Start at 1 since we have at least one node

    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Connect the last node to the head
    temp->next = *head;

    // Calculate effective rotation
    k = k % count; // In case k is larger than count
    if (k == 0)
    {
        temp->next = NULL; // No change needed
        return;
    }

    // Find the new tail node
    int newTailPosition = count - k;
    temp = *head;
    for (int i = 1; i < newTailPosition; i++)
        temp = temp->next;

    // Update head and break the loop
    *head = temp->next;
    temp->next = NULL;
}