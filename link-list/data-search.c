#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head;

void search(node *head)
{
    node *current = head;
    int n, f = 0;
    printf("Enter the search data : ");
    scanf("%d", &n);
    while (current != NULL)
    {
        if (current->data == n)
        {
            f = 1;
            break;
        }
        current = current->next;
    }
    if (f == 1)
    {
        printf("Found Data Item in this node \n");
    }
    else
    {
        printf("Not found Data Item in this node\n");
    }
}

void printdata(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
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

    printdata(head);
    printf("\n");
    search(head);
}