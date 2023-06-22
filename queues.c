#include <stdio.h>
#include <stdlib.h>

typedef struct Node // Node create*****
{
    int data;
    struct Node *next;
} node;

node *top = NULL; // global decleard top = NULL****

void enqueue(int data) // enqueue function****
{
    node *newnode = (node *)malloc(sizeof(node)); // newnode make***
    newnode->data = data;
    newnode->next = NULL;
    if (top == NULL) // top null hole top = newnode hobe***
    {
        top = newnode;
    }
    else
    {
        node *current = top; // curernt node er moddde top rhaklam***
        while (current->next != NULL)
        {
            current = current->next; // current 1 ghor kore agaiye jaoya*****
        }
        current->next = newnode; // current last node ta newnode kora****
    }
}

void dequeue() // dequeue function****
{
    node *newnode; // newnode**
    if (top == NULL)
    {
        printf("queues is empty!!!\n");
    }
    else
    {
        newnode = top; // 10,20,30  ...newnode =10...top = 20,top=30,
        top = top->next;
        free(newnode); // newnode 10 free
    }
}

void printdata()
{
    node *temp = top;
    printf("enqueue data is : ");
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
    printf("how many data enqueue : ");
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &m);
        enqueue(m);
        printdata();
    }
    printf("\n");
    printf("how many data you dequeue : ");
    scanf("%d", &n);
    printf("\n");
    for (j = 0; j < n; j++)
    {
        dequeue();
        printdata();
    }
    return 0;
}