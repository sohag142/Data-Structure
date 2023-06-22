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

void insert_at_mid(node *head, int data, int position)
{
    node *current = head;
    int count = 1;
    while (current != NULL)
    {
        count++;
        if (count == position)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->data = data;
            temp->next = current->next;
            current->next = temp;
        }

        current = current->next;
    }
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
    insert_at_mid(head, 60, 2);
    printdata(head);
    return 0;
}
