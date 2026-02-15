#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to insert a new node after a given node
void insertAfter(Node *prevNode, int newData) 
{
    if (prevNode == NULL) 
    {
        printf("Cannot insert after NULL node.\n");
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = newData;

    // Link new node
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL) 
    {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// Function to delete a node with given data
void deleteNode(Node **head, int data) 
{
    Node *current = *head;
    while (current != NULL && current->data != data) 
    {
        current = current->next;
    }
    if (current == NULL) return; 
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next; 
    if (current->next != NULL)
        current->next->prev = current->prev;
    free(current);
}

// Function to print list forward
void printList(Node *head) 
{
    Node *current = head;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() 
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;

    Node *second = (Node*)malloc(sizeof(Node));
    second->data = 20;
    second->prev = head;
    second->next = NULL;
    head->next = second;

    Node *third = (Node*)malloc(sizeof(Node));
    third->data = 30;
    third->prev = second;
    third->next = NULL;
    second->next = third;

    printf("Initial list: ");
    printList(head);

    insertAfter(second, 25);
    printf("After inserting 25 after 20: ");
    printList(head);

    deleteNode(&head, 10);
    printf("After deleting 10: ");
    printList(head);

    deleteNode(&head, 30);
    printf("After deleting 30: ");
    printList(head);

    insertAfter(head, 15);
    printf("After inserting 15 after head: ");
    printList(head);

    return 0;
}
