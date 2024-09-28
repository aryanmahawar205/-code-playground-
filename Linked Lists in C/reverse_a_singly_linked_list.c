#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createLinkedList(struct node **head, int num);
void displayLinkedList(struct node **head);
void reverseLinkedList(struct node **head);
void releaseLinkedListMemory(struct node **head);

int main()
{
    int num; printf("Enter the number of elements you want to have in the Linked list - ");
    scanf("%d", &num); printf("\n");

    struct node *head = NULL;
    createLinkedList(&head, num);
    printf("\nLinked List created with data: ");
    displayLinkedList(&head);

    reverseLinkedList(&head);
    printf("\n\nLinked List reversed as: ");
    displayLinkedList(&head);

    releaseLinkedListMemory(&head);

    return 0;
}

void createLinkedList(struct node **head, int num)
{
    struct node *temp = NULL; struct node *newNode;
    while(num != 0)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data - "); scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(*head == NULL)
            *head = temp = newNode;

        else
        {
            temp->next = newNode;
            temp = newNode;
        }

        num--;
    }
}

void displayLinkedList(struct node **head)
{
    struct node *temp; temp = *head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverseLinkedList(struct node **head)
{
    struct node *prevNode; struct node *currentNode; struct node *nextNode;
    prevNode = NULL; currentNode = nextNode = *head;
    while(nextNode != NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *head = prevNode;
}

void releaseLinkedListMemory(struct node **head)
{
    struct node *temp;
    temp = *head;
    while(temp != NULL)
    {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}
