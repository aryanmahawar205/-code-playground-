// Removing duplicates from a sorted Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createLinkedList(struct node **head, int num);
void printLinkedList(struct node **head);
void sortLinkedList(struct node **head);
void freeLinkedListMemory(struct node **head);
void removeDuplicatesFromLinkedList(struct node **head);


int main()
{
    struct node *head = NULL;
    int num; printf("Enter the number of elements you wish to have in the linked list - "); scanf("%d", &num);
    printf("\n");
    createLinkedList(&head, num);
    printf("\nLinked list data: ");
    printLinkedList(&head);
    sortLinkedList(&head);
    printf("\nLinked list sorted: ");
    printLinkedList(&head);
    printf("\nLinked list data after removing duplicates: ");
    removeDuplicatesFromLinkedList(&head);
    printLinkedList(&head);

    return 0;
}

void removeDuplicatesFromLinkedList(struct node **head)
{
    struct node *temp; temp = *head;
    struct node *q;
    
    while(temp != NULL && temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            q = temp->next->next;
            temp->next = q;
        }
        temp = temp->next;
    }
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

void sortLinkedList(struct node **head)
{
    struct node *ptr; struct node *cpt;
    ptr = *head;
    while (ptr->next != NULL)
    {
        cpt = ptr->next;
        while (cpt != NULL)
        {
            if (ptr->data > cpt->data)
            {
                int temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
            cpt = cpt->next;
        }
        ptr = ptr->next;
    }
}