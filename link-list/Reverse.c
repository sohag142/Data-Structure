#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void printdata(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

void reverselinklist(node *head)
{
    node *prev = NULL;
    node *current = head;
    node *stor = NULL;

    while (current != NULL)
    {
        stor = current->next; // 10,20,30..s=20,p=10,c=20
        current->next = prev;
        prev = current;
        current = stor;
    }
    head = prev;

    printdata(head);
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
    reverselinklist(head);

    return 0;
}
