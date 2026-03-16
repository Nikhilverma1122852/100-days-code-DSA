#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal
void preorder(struct Node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);   // Visit root
    preorder(root->left);        // Traverse left
    preorder(root->right);       // Traverse right
}

int main()
{
    // Creating tree manually
    struct Node* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("Preorder Traversal: ");
    preorder(root);

    return 0;
}