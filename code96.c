#include <stdio.h>
#include <stdlib.h>

// Define TreeNode (needed in VS Code)
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate sum of left leaves
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check if left child is a leaf
    if (root->left != NULL &&
        root->left->left == NULL &&
        root->left->right == NULL) {
        sum += root->left->val;
    }

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    // Constructing the tree:
    //        3
    //       / \
    //      9  20
    //         / \
    //        15  7

    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int result = sumOfLeftLeaves(root);

    printf("Sum of left leaves: %d\n", result);

    return 0;
}