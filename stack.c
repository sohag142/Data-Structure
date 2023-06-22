#include <stdio.h>
#include <stdlib.h>

typedef struct Node // node create
{
    int data;
    struct Node *next;
} node;

node *top = NULL; // globar declared top null*****

void push(int data) // push funtion***
{
    node *newnode = (node *)malloc(sizeof(node)); // newnode create****
    newnode->data = data;
    newnode->next = NULL;
    if (top == NULL)
    {
        top = newnode; // if top null hoyy top = newnode hoye jabee****
    }
    else
    {
        node *current = top;          // currrent node er modde top rhaklam***
        while (current->next != NULL) // while condition
        {
            current = current->next;
        }
        current->next = newnode; // current er last e newnode add hobee****
    }
}

void pop() // pop function******
{
    node *current = top;
    node *prev; // previous node create***
    if (top == NULL)
    {
        printf("stack is empty!!\n");
        return;
    }
    else
    {
        while (current->next != NULL) // while condition****
        {
            prev = current; // 10,20,30   ... p=10,c=20,..p =20,c=30....
            current = current->next;
        }
        prev->next = current->next; // p=20=null
        free(current);              // current free
    }
}

void printdata()
{
    node *temp = top;
    printf("push data is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int i, j, m, k, n;
    printf("how many data insert : ");
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &m);
        push(m);
        printdata();
    }
    printf("\n");
    printf("how many data you deleted : ");
    scanf("%d", &n);
    printf("\n");
    for (j = 0; j < n; j++)
    {
        pop();
        printdata();
    }
    return 0;
}