#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head;

void insert_any(int data)
{
    int count = 1, n;
    printf("Enter the position : ");
    scanf("%d", &n);
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (n == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        node *current = head;
        while (count < n - 1)
        {
            current = current->next;
            count++;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void printData()
{
    node *current = head;
    printf("New list is:");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->data = 3;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 10;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 2;
    head->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->data = 1;
    head->next->next->next->next = NULL;
    printData();
    insert_any(50);
    printf("\n");
    printf("Final ");
    printData();
}