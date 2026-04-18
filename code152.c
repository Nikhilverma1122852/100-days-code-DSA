#include <stdio.h>
#include <stdlib.h>

#define MAX 101

// Node structure
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Visited array for cloning
struct Node* visited[MAX];

// DFS clone function
struct Node* dfs(struct Node* s) {
    if (visited[s->val] != NULL)
        return visited[s->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * s->numNeighbors);

    visited[s->val] = clone;

    for (int i = 0; i < s->numNeighbors; i++) {
        clone->neighbors[i] = dfs(s->neighbors[i]);
    }

    return clone;
}

// Clone Graph function
struct Node* cloneGraph(struct Node* s) {
    if (s == NULL) return NULL;

    for (int i = 0; i < MAX; i++)
        visited[i] = NULL;

    return dfs(s);
}

// Function to print graph (DFS)
void printGraph(struct Node* node, int visitedPrint[]) {
    if (!node || visitedPrint[node->val]) return;

    visitedPrint[node->val] = 1;

    printf("Node %d: ", node->val);
    for (int i = 0; i < node->numNeighbors; i++) {
        printf("%d ", node->neighbors[i]->val);
    }
    printf("\n");

    for (int i = 0; i < node->numNeighbors; i++) {
        printGraph(node->neighbors[i], visitedPrint);
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Empty graph\n");
        return 0;
    }

    struct Node* nodes[MAX];

    // Create nodes
    for (int i = 1; i <= n; i++) {
        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
        nodes[i]->val = i;
        nodes[i]->numNeighbors = 0;
        nodes[i]->neighbors = NULL;
    }

    // Input adjacency list
    for (int i = 1; i <= n; i++) {
        int k;
        printf("Enter number of neighbors of node %d: ", i);
        scanf("%d", &k);

        nodes[i]->numNeighbors = k;
        nodes[i]->neighbors = (struct Node**)malloc(sizeof(struct Node*) * k);

        printf("Enter neighbors: ");
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            nodes[i]->neighbors[j] = nodes[x];
        }
    }

    // Clone graph starting from node 1
    struct Node* cloned = cloneGraph(nodes[1]);

    // Print cloned graph
    printf("\nCloned Graph:\n");
    int visitedPrint[MAX] = {0};
    printGraph(cloned, visitedPrint);

    return 0;
}