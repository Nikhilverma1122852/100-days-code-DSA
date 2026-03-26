#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue
struct TreeNode* queue[2000];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue();

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzag(struct TreeNode* root) {
    if (!root) {
        printf("[]");
        return;
    }

    front = rear = 0;
    enqueue(root);

    int leftToRight = 1;

    printf("[");

    while (!isEmpty()) {
        int size = rear - front;
        int arr[2000];

        printf("[");

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue();

            int index = leftToRight ? i : (size - 1 - i);
            arr[index] = node->val;

            if (node->left) enqueue(node->left);
            if (node->right) enqueue(node->right);
        }

        for (int i = 0; i < size; i++) {
            printf("%d", arr[i]);
            if (i < size - 1) printf(",");
        }

        printf("]");

        if (!isEmpty()) printf(",");

        leftToRight = !leftToRight;
    }

    printf("]");
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    zigzag(root);

    return 0;
}