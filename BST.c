
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void pre_order(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

void post_order(node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}

node *insertnode(node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
        return root;
    }
    else if (data > root->data)
    {
        root->right = insertnode(root->right, data);
    }
    else
    {
        root->left = insertnode(root->left, data);
    }
    return root;
}

void search(node *root, int data)
{
    if (root != NULL)
    {
        if (root->data == data)
        {
            printf("Data found\n");
        }
        else if (root->data < data)
        {
            search(root->right, data);
        }
        else if (root->data > data)
        {
            search(root->left, data);
        }
    }

    else
    {
        printf("  Data NOt Found\n");
    }
}

int main()
{
    node *root = NULL;
    root = insertnode(root, 20);
    root = insertnode(root, 18);
    root = insertnode(root, 22);
    root = insertnode(root, 21);
    root = insertnode(root, 16);
    root = insertnode(root, 23);
    root = insertnode(root, 15);
    root = insertnode(root, 25);
    root = insertnode(root, 14);
    root = insertnode(root, 28);
    printf("\n\n");
    printf("pre_order : ");
    pre_order(root);
    printf("\n\n");
    printf("In_order : ");
    in_order(root);
    printf("\n\n");
    printf("post_order : ");
    post_order(root);
    printf("\n\n");

    search(root, 10);
}
