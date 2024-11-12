#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50
struct node
{
    char data[30];
    struct node *left, *right;
};

struct node *stack[size];
int top = -1;

void push(struct node *node)
{
    if (top == size - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = node;
}

struct node *pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}

// always a different copy of the local variales is created  in the stack for each function call
// when x is -1 0 is returned to the caller

struct node *create()
{
    char x[30];
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Data:(-1 for no node):");
    scanf("%s", x);
    // if (x == -1)
    // {
    //     return 0;
    // }
    if (strcmp(x, "-1") == 0)
    {
        return 0;
    }
    // newnode->data = x;
    strcpy(newnode->data, x);
    printf("\nEnter left child of  %s\n", x);
    newnode->left = create();
    printf("\nEnter right child of  %s\n", x);
    newnode->right = create();
    return newnode;
}
void inorder_r(struct node *root)
{
    if (root != NULL)
    {
        inorder_r(root->left);
        printf("%s\t", root->data);
        inorder_r(root->right);
    }
}

void preorder_r(struct node *root)
{
    if (root != NULL)
    {
        printf("%s\t", root->data);
        preorder_r(root->left);
        preorder_r(root->right);
    }
}

void postorder_r(struct node *root)
{
    if (root != NULL)
    {
        postorder_r(root->left);
        postorder_r(root->right);
        printf("%s\t", root->data);
    }
}

void inorder(struct node *root)
{
    struct node *curr;
    curr = root;
    while (1)
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        if (top == -1)
        {
            break;
        }
        curr = pop();
        printf("%s\t", curr->data);
        curr = curr->right;
    }
}

void preorder(struct node *root)
{
    struct node *curr;
    curr = root;
    while (1)
    {
        while (curr != NULL)
        {
            printf("%s\t", curr->data);
            push(curr);
            curr = curr->left;
        }
        if (top == -1)
        {
            break;
        }
        curr = pop();
        curr = curr->right;
    }
}

void postorder(struct node *root)
{
    struct node *curr;
    curr = root;
    while (1)
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }

        if (stack[top]->right == NULL)
        {
            curr = pop();
            printf("%s\t", curr->data);
        }
        while (top != -1 && stack[top]->right == curr)
        {
            curr = pop();
            printf("%s\t", curr->data);
        }
        if (top == -1)
        {
            break;
        }
        curr = stack[top]->right;
    }
}
int main()
{
    struct node *root = 0;
    root = create();
    printf("\n-----------RECURSIVE INORDER TRAVERSAL-----------\n\n");
    inorder_r(root);
    printf("\n-----------RECURSIVE PREORDER TRAVERSAL-----------\n\n");
    preorder_r(root);
    printf("\n----------RECURSIVE POSTORDER TRAVERSAL-----------\n\n");
    postorder_r(root);
    printf("\n-----------NONRECURSIVE INORDER TRAVERSAL-----------\n\n");
    inorder(root);
    printf("\n-----------NONRECURSIVE PREORDER TRAVERSAL-----------\n\n");
    preorder(root);
    printf("\n-----------NONRECURSIVE POSTORDER TRAVERSAL-----------\n\n");
    postorder(root);
    return 0;
}