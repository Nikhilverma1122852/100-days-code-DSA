#include <stdio.h>
#include <stdlib.h>

// Define Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder Traversal (sorted output)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int n, val, insertVal;

    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertIntoBST(root, val);
    }

    printf("Enter value to insert: ");
    scanf("%d", &insertVal);

    root = insertIntoBST(root, insertVal);

    printf("Inorder Traversal after insertion: ");
    inorder(root);

    return 0;
}