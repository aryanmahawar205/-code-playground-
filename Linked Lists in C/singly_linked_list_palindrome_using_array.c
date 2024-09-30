// Linked List is Palindrome or not using Stack DS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

void createLinkedList(struct node **head, int num);
void displayLinkedList(struct node **head);
void clearLinkedListMemory(struct node **head);
bool checkIfPalindrome(struct node **head);

int main()
{
    int num; printf("Enter the number of elements you want in the Linked List - "); scanf("%d", &num); printf("\n");
    
    struct node *head = NULL;
    createLinkedList(&head, num);
    printf("\nLinked List Data: ");
    displayLinkedList(&head);
    
    if (checkIfPalindrome(&head))
        printf("\nLinked List is a Palindrome!");
        
    else
        printf("\nLinked List is not a Palindrome");
        
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

bool checkIfPalindrome(struct node **head)
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
    
    // copy elements to the array
    while(temp != NULL)
    {
        array[indexArray++] = temp->data;
        temp = temp->next;
    }
    
    // reverse the array
    for (int i = 0; i < count/2; i++)
    {
        if (array[i] != array[count-i-1])
            return false;
        
        return true;
    }
}