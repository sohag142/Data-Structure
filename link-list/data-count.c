#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head;

void count(node *head)
{
    int c = 0;
    node *current = head;
    while (current != NULL)
    {
        c++;
        current = current->next;
    }
    printf("Total count number : %d ", c);
}

void printData(node *head)
{
    node *current = head;
    printf("New list is:");
    while (current != NULL)
    {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->data = 10;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 20;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 30;
    head->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;
    printData(head);
    printf("\n");
    count(head);
}