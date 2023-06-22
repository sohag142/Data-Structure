#include <stdio.h>
#include <stdlib.h>

// Node for Doubly Linked List
typedef struct node
{
    int key;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;
node *first;
node *last;
node *temp;

void addnode(int k)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->key = k;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL)
    {
        head = ptr;
        first = head;
        last = head;
    }
    else
    {
        temp = ptr;
        first->next = temp;
        temp->prev = first;
        first = temp;
        last = temp;
    }
}
void traverse()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        // Print key of the node
        printf("%d <-> ", ptr->key);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    addnode(10);
    addnode(20);
    addnode(30);
    traverse();
    return 0;
}