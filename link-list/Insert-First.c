#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head;
node *newnode;

void printdata(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return;
}

void insert_at_begining(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head = temp;
    newnode = head;
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 10;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 20;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    printdata(head);
    insert_at_begining(head, 50);
    printdata(newnode);
    return 0;
}