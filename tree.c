#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void add_left_child(node *root, node *child)
{
    root->left = child;
}

void add_right_child(node *root, node *child)
{
    root->right = child;
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

int main()
{
    node *ten = create_node(10);
    node *tw = create_node(20);
    node *th = create_node(30);
    node *fu = create_node(40);
    add_left_child(ten, tw);
    add_right_child(ten, th);
    add_left_child(tw, fu);
    printf("Pre order: ");
    pre_order(ten);
    printf("\n");
    printf("In order: ");
    in_order(ten);
    printf("\n");
    printf("Post order: ");
    post_order(ten);
}