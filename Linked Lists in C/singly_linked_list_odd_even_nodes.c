// Linked List Odd Even nodes using temporary array

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createLinkedList(struct node **head, int num);
void displayLinkedList(struct node **head);
void clearLinkedListMemory(struct node **head);
void oddEvenLinkedList(struct node **head);

int main()
{
    int num; printf("Enter the number of elements you want in the Linked List - "); scanf("%d", &num); printf("\n");
    
    struct node *head = NULL;
    createLinkedList(&head, num);
    printf("\nLinked List Data before replacement: ");
    displayLinkedList(&head);
    
    oddEvenLinkedList(&head);
    printf("\nLinked List Data after replacement: ");
    displayLinkedList(&head);
    
    clearLinkedListMemory(&head);
    
    return 0;
}

void createLinkedList(struct node **head, int num)
{
    struct node *newNode; struct node *temp;
    
    while(num != 0)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data - ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        if(*head == NULL)
        {
            *head = temp = newNode;
        }
        
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

void clearLinkedListMemory(struct node **head)
{
    struct node *temp; temp = *head;
    
    while(temp != NULL)
    {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

void oddEvenLinkedList(struct node **head)
{
    struct node *temp; temp = *head; int count = 0;
    
    // calculate length of Linked List
    while(temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    
    int array[count]; int indexArray = 0;
    
    temp = *head;
    
    // copy odd elements to the array
    while(temp != NULL && temp->next != NULL)
    {
        array[indexArray++] = temp->data;
        temp = temp->next->next;
    }
    if (temp)
        array[indexArray++] = temp->data;
    
    temp = *head; temp = temp->next;
    
    // copy even elements to the array
    while(temp != NULL && temp->next != NULL)
    {
        array[indexArray++] = temp->data;
        temp = temp->next->next;
    }
    if (temp)
        array[indexArray++] = temp->data;
    
    // replace array data into Linked List
    temp = *head; indexArray = 0;
    while(temp != NULL)
    {
        temp->data = array[indexArray++];
        temp = temp->next;
    }
}