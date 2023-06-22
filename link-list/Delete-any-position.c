#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head;

void deleteanyposition(node *head)
{
    int i, position, count = 1;
    node *current = head;
    node *prev;
    printf("Enter your Position: ");
    scanf("%d", &position);
    if (position == 1)
    {
        head = head->next;
        free(current);
    }
    else
    {
        node *current = head;
        while (count < position)
        {
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        free(current);
    }
}

void printdata(node *head)
{
    node *current = head;
    printf("New node : ");
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
    head->next->data = 200;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 30;
    head->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;
    printdata(head);
    deleteanyposition(head);
    printf("\n");
    printf("Final ");
    printdata(head);
}
