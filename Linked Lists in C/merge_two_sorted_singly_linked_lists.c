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
struct node* mergeTwoSortedLinkedList(struct node **head1, struct node **head2, struct node *sorting);
void freeLinkedListMemory(struct node **head);


int main()
{
    struct node *head1 = NULL;
    int num1; printf("Enter the number of elements you wish to have in the first linked list - "); scanf("%d", &num1);
    printf("\n");
    createLinkedList(&head1, num1);
    printf("\nFirst Linked list data: ");
    printLinkedList(&head1);
    sortLinkedList(&head1);
    printf("\nFirst Linked list sorted: ");
    printLinkedList(&head1);

    struct node *head2 = NULL;
    int num2; printf("\n\nEnter the number of elements you wish to have in the second linked list - "); scanf("%d", &num2);
    printf("\n");
    createLinkedList(&head2, num2);
    printf("\nSecond Linked list data: ");
    printLinkedList(&head2);
    sortLinkedList(&head2);
    printf("\nSecond Linked list sorted: ");
    printLinkedList(&head2);

    struct node *sorting = NULL;
    struct node *newHead = mergeTwoSortedLinkedList(&head1, &head2, sorting);
    printf("\n\nAfter merging in sorted manner, Linked list data: ");
    printLinkedList(&newHead);


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

struct node* mergeTwoSortedLinkedList(struct node **head1, struct node **head2, struct node *sorting)
{
    struct node *newHead = NULL; struct node *p = *head1; struct node *q = *head2;

    if (p && q)
    {
        if (p->data <= q->data)
        {
            sorting = p;
            p = sorting->next;
        }

        else
        {
            sorting = q;
            q = sorting->next;
        }
    }
    newHead = sorting;

    while (p && q)
    {
        if (p->data <= q->data)
        {
            sorting->next = p;
            sorting = p;
            p = sorting->next;
        }

        else
        {
            sorting->next = q;
            sorting = q;
            q = sorting->next;
        }
    }

    if (p == NULL)
        sorting->next = q;

    if (q == NULL)
        sorting->next = p;

    return newHead;
}
