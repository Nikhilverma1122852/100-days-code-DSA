#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Search element in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree function
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Pick current root
    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(curr);

    // If only one node
    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, curr);

    // Build right subtree first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal (Output required)
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    // Input inorder
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    // Input postorder
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    // Build tree
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    // Print preorder traversal
    preorder(root);

    return 0;
}