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

int main()
{
    struct node *head = NULL; struct node *temp = NULL;
    int num; printf("Enter the number of elements you want in the linked list - "); scanf("%d", &num);
    printf("\n");

    createLinkedList(&head, num);

    printf("\nLinked list before sorting: ");
    printLinkedList(&head);

    sortLinkedList(&head);
    printf("\nLinked list after sorting: ");
    printLinkedList(&head);

    freeLinkedListMemory(&head);

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
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortLinkedList(struct node **head)
{
    struct node *ptr; struct node *cpt; int temp;
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

void freeLinkedListMemory(struct node **head)
{
    struct node *temp = NULL;
    temp = *head;
    while (temp != NULL)
    {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}
