#include <stdio.h>
#include <stdlib.h>


struct tbtnode {
    char value;     
    int rightBit, leftBit;  
    struct tbtnode *rightChild, *leftChild; 
};


struct tbtnode* Insuccessor(struct tbtnode *node) {
    struct tbtnode *successor = node->rightChild;
    if (node->rightBit == 1) {
        while (successor->leftBit == 1) {
            successor = successor->leftChild;
        }
    }
    return successor;
}


void InoTraversal(struct tbtnode *header) {
    struct tbtnode *currentNode = header;
    while (1) {
        currentNode = Insuccessor(currentNode);
        if (currentNode == header) break;
        printf("%c ", currentNode->value);
    }
}


void create(struct tbtnode *header) {
    struct tbtnode *root, *tempNode, *newNode;
    char input1, input;

    
    root = (struct tbtnode*)malloc(sizeof(struct tbtnode));
    printf("Enter Root value : ");
    scanf(" %c", &root->value);

    
    root->leftChild = header;
    root->rightChild = header;
    root->leftBit = root->rightBit = 0;

    
    header->leftChild = root;
    header->leftBit = 1;

    do {
        int done = 0;
        tempNode = root;

        newNode = (struct tbtnode*)malloc(sizeof(struct tbtnode));
        printf("Enter New node Value : ");
        scanf(" %c", &newNode->value);

        newNode->leftBit = newNode->rightBit = 0;

        while (done == 0) {
            printf("Select position (l - left, r - right) of %c: ", tempNode->value);
            scanf(" %c", &input1);

            if (input1 == 'l') {
                if (tempNode->leftBit == 0) {
                    newNode->rightChild = tempNode;
                    newNode->leftChild = tempNode->leftChild;
                    tempNode->leftChild = newNode;
                    tempNode->leftBit = 1;
                    done = 1;
                } else {
                    tempNode = tempNode->leftChild;
                }
            }

            if (input1 == 'r') {
                if (tempNode->rightBit == 0) {
                    newNode->leftChild = tempNode;
                    newNode->rightChild = tempNode->rightChild;
                    tempNode->rightChild = newNode;
                    tempNode->rightBit = 1;
                    done = 1;
                } else {
                    tempNode = tempNode->rightChild;
                }
            }
        }

        printf("Wanna continue ? (y/n): ");
        scanf(" %c", &input);
    } while (input == 'y');
}

int main() {
    struct tbtnode *header = (struct tbtnode*)malloc(sizeof(struct tbtnode));

    header->rightBit = 1;
    header->leftBit = 0;
    header->leftChild = header;
    header->rightChild = header;

    create(header);

    printf("Inorder Traversal: ");
    InoTraversal(header);
    printf("\n");

    return 0;
}


/* 

Enter Root value : J
Enter New node Value : R
Select position (l - left, r - right) of J: l
Do you want to add another node? (y/n): y
Enter New node Value : D
Select position (l - left, r - right) of J: l
Select position (l - left, r - right) of R: l
Do you want to add another node? (y/n): y
Enter New node Value : Z
Select position (l - left, r - right) of J: l
Select position (l - left, r - right) of R: l
Select position (l - left, r - right) of Z: l
Do you want to add another node? (y/n): y
Enter New node Value : I
Select position (l - left, r - right) of J: l
Select position (l - left, r - right) of R: l
Select position (l - left, r - right) of Z: r
Do you want to add another node? (y/n): y
Enter New node Value : E
Select position (l - left, r - right) of J: l
Select position (l - left, r - right) of R: r
Do you want to add another node? (y/n): y
Enter New node Value : Z
Select position (l - left, r - right) of J: r
Do you want to add another node? (y/n): y
Enter New node Value : F
Select position (l - left, r - right) of J: r
Select position (l - left, r - right) of Z: l
Do you want to add another node? (y/n): y
Enter New node Value : M
Select position (l - left, r - right) of J: r
Select position (l - left, r - right) of Z: r
Do you want to add another node? (y/n): n

Inorder Traversal: Z D I R E J F Z M

*/