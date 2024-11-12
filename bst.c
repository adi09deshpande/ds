#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct queueNode 
{
    struct bst *treeNode;
    struct queueNode *next;
}; 

struct bst 
{
    char word[10];
    char meaning[20];
    struct bst *left;
    struct bst *right;
};

struct bst *stack[SIZE];
int top = -1;

int isEmptyStack() 
{
    return top == -1;
}

void push(struct bst *node) 
{
    if (top == SIZE - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = node;
}

struct bst* pop() 
{
    if (top == -1) 
    {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}

struct bst *queue[SIZE];
int front = 0, rear = -1;

int isQueueEmpty(struct queueNode *front) 
{
    return front == NULL;
}

void enqueue(struct queueNode **front, struct queueNode **rear, struct bst *node) 
{
    struct queueNode *newNode = (struct queueNode*)malloc(sizeof(struct queueNode));
    if (newNode == NULL) 
    {
        printf("Memory allocation error.\n");
        return;
    }
    newNode->treeNode = node;
    newNode->next = NULL;
    if (*rear == NULL) 
    {
        *front = *rear = newNode;
    } 
    else 
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

struct bst* dequeue(struct queueNode **front, struct queueNode **rear) 
{
    if (*front == NULL) 
    {
        printf("Queue is empty.\n");
        return NULL;
    }
    struct queueNode *temp = *front;
    struct bst *node = temp->treeNode;
    *front = (*front)->next;
    if (*front == NULL) 
    {
        *rear = NULL;
    }
    free(temp);
    return node;
}

void create(struct bst *root)
{
    struct bst *temp, *curr;
    int choice;
    int flag;
    do
    {
        temp = root;
        flag = 0;
        curr = (struct bst *)malloc(sizeof(struct bst));
        printf("Enter Word: ");
        scanf("%s", curr->word);
        printf("Enter Meaning: ");
        scanf("%s", curr->meaning);
        curr->left = NULL;
        curr->right = NULL;
        
        while(flag == 0)
        {
            if(strcmp(curr->word, temp->word) < 0)
            {
                if(temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        printf("\nDo you want to add another node (1 for yes, 0 for no): ");
        scanf(" %d", &choice);
    } while(choice == 1);
}

void inorder(struct bst *root) 
{
    struct bst *temp;
    temp = root;
    while (1) 
    {
        while (temp != NULL) 
        {
            push(temp);
            temp = temp->left;
        }
        if (isEmptyStack()) 
        {
            break;
        }
        temp = pop();
        printf("Word: %s\n", temp->word);
        printf("Meaning: %s\n", temp->meaning);
        temp = temp->right;
    }
}

/*void insert(struct bst** root, char word[], char meaning[])
{
    if (*root == NULL) 
    {
        struct bst* newNode = (struct bst*)malloc(sizeof(struct bst));
        if (newNode == NULL) 
        {
            printf("Memory allocation error\n");
            return;
        }
        int i = 0;
        while (word[i] != '\0') 
        {
            newNode->word[i] = word[i];
            i++;
        }
        newNode->word[i] = '\0';
        int j = 0;
        while (meaning[j] != '\0') 
        {
            newNode->meaning[j] = meaning[j];
            j++;
        }
        newNode->meaning[j] = '\0';
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
        return;
    }
    if (strcmp(word, (*root)->word) < 0) 
    {
        insert(&((*root)->left), word, meaning);
    } 
    else if (strcmp(word, (*root)->word) > 0) 
    {
        insert(&((*root)->right), word, meaning);
    }
}*/

void delete(struct bst **root, char word[])
{
    struct bst *temp, *curr, *s;
    struct bst *parent = NULL;
    curr = *root;
    while (curr != NULL && strcmp(curr->word, word) != 0) 
    {
        parent = curr;
        if (strcmp(word, curr->word) < 0) 
        {
            curr = curr->left;
        } 
        else 
        {
            curr = curr->right;
        }
    }
    if(curr == *root)
    {
        if(curr->right == NULL)
        {
            *root = curr->left;
        }
        else if(curr->left == NULL)
        {
            *root = curr->right;
        }
        else if(curr->right != NULL && curr->left != NULL)
        {
            temp = curr->left;
            *root = curr->right;
            s = curr->right;
            while(s->left != NULL)
            {
                s = s->left;
            }
            s->left = temp;
        }
    }
    else if(curr != *root)
    {
        if(curr->left == NULL && curr->right == NULL)
        {
            if(parent->left == curr)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        else if(curr->left == NULL)
        {
            if(parent->left == curr)
            {
                parent->left = curr->right;
            }
            else
            {
                parent->right = curr->right;
            }
        }
        else if(curr->right == NULL)
        {
            if(parent->left == curr)
            {
                parent->left = curr->left;
            }
            else
            {
                parent->right = curr->left;
            }
        }
        else
        {
            s = curr->right;
            temp = curr->left;
            while(s->left != NULL)
            {
                s= s->left;
            }
            s->left = temp;
            if(parent->left == curr)
            {
                parent->left = curr->right;
            }
            else
            {
                parent->right = curr->right;
            }
        }
        curr->left == NULL;
        curr->right == NULL;
    }
    free(curr);
    printf("Node with word '%s' deleted successfully.\n", word);
}

void BFS(struct bst *root) 
{
    if (root == NULL) 
    {
        printf("Tree is empty.\n");
        return;
    }

    struct queueNode *front = NULL;
    struct queueNode *rear = NULL;
    enqueue(&front, &rear, root);

    while (!isQueueEmpty(front)) 
    {
        struct bst *temp = dequeue(&front, &rear);
        printf("Word: %s, Meaning: %s\n", temp->word, temp->meaning);

        if (temp->left != NULL) 
        {
            enqueue(&front, &rear, temp->left);
        }

        if (temp->right != NULL) 
        {
            enqueue(&front, &rear, temp->right);
        }
    }
}

void copy(struct bst *root2)
{
    if (root2 == NULL)
    {
        printf("Original tree is empty.\n");
        return;
    }
    struct bst *root1 = (struct bst *)malloc(sizeof(struct bst));
    struct bst *temp1 = root1, *temp2 = root2;
    strcpy(temp1->word, temp2->word);
    strcpy(temp1->meaning, temp2->meaning);
    temp1->left = temp1->right = NULL;

    while (1)
    {
        while (temp2 != NULL)
        {
            if (temp2->left != NULL)
            {
                temp1->left = (struct bst *)malloc(sizeof(struct bst));
                strcpy(temp1->left->word, temp2->left->word);
                strcpy(temp1->left->meaning, temp2->left->meaning);
                temp1->left->left = temp1->left->right = NULL;
            }
            if (temp2->right != NULL)
            {
                temp1->right = (struct bst *)malloc(sizeof(struct bst));
                strcpy(temp1->right->word, temp2->right->word);
                strcpy(temp1->right->meaning, temp2->right->meaning);
                temp1->right->left = temp1->right->right = NULL;
            }
            push(temp1);
            push(temp2);
            temp1 = temp1->left;
            temp2 = temp2->left;
        }
        if (isEmptyStack())
        {
            break;
        }
        temp2 = pop();
        temp1 = pop();
        temp1 = temp1->right;
        temp2 = temp2->right;
    }
    printf("Inorder traversal of the copied tree:\n");
    inorder(root1);
}

void mirror(struct bst *root)
{
    if (root == NULL)
    {
        return;
    }
    struct bst *temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root->left != NULL)
    {
        mirror(root->left);
    }
    if (root->right != NULL)
    {
        mirror(root->right);
    }
}

int main()
{
    struct bst *root = NULL;
    root = (struct bst *)malloc(sizeof(struct bst));

    printf("Enter word for the root node: ");
    scanf("%s", root->word);
    printf("Enter meaning for the root node: ");
    scanf("%s", root->meaning);
    root->left = NULL;
    root->right = NULL;

    int choice;
    char word[10], meaning[20];

    do {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Inorder Traversal\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node\n");
        printf("5. Copy and Display\n");
        printf("6. Mirror\n");
        printf("7. Display Level-wise\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(root);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                create(root);
                break;
            case 4:
                printf("Enter the word to delete: ");
                scanf("%s", word);
                delete(&root, word);
                break;
            case 5:
                copy(root);
                break;
            case 6:
                mirror(root);
                BFS(root);
                break;
            case 7:
                BFS(root);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 8);
    return 0;
}