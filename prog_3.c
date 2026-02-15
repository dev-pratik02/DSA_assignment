#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node 
{
    int data;
    struct Node* next;
};

// Function to perform reverse traversal
void reverseTraversal(struct Node* head) 
{
    if (head == NULL)
        return;
    reverseTraversal(head->next);
    printf("%d ", head->data);
}

int main() 
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Reverse Traversal: ");
    reverseTraversal(head); // Output: 30 20 10

    return 0;
}
