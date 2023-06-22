
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head;

void deleteData(node *head)
{
    int n;
    node *current = head, *prev;
    printf("Enter the deleted data : ");
    scanf("%d", &n);

    if (head->data == n)
    {
        head = head->next;
        free(current);
    }
    else
    {
        while (current != NULL && current->data != n)
        {
            prev = current;
            current = current->next;
        }

        if (current->data == n)
        {
            prev->next = current->next;
            free(current);
        }
    }
}

void printData(node *head)
{
    node *current = head;
    printf("New list is: ");
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
    deleteData(head);
    printf("\n");
    printf("Final ");
    printData(head);
}