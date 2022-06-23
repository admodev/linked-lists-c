#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // put in the data
    new_node->data  = new_data;

    // Make next of new node as head
    new_node->next = (*head_ref);

    // Move the head to point to the new node
    (*head_ref)    = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    // Check if the given prev_node is NULL
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    // Allocate new node
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    // Put the data in
    new_node->data  = new_data;

    // Make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // Move the next of prev_node as new_node
    prev_node->next = new_node;
}

// And so on...
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->data  = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node* head = NULL;

    // Insert 6.  So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    printf("\n Created Linked list is: ");
    printList(head);
    printf("\n");

    return 0;
}
