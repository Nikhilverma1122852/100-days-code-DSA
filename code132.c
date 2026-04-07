#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (b -> a)
void addEdge(int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// DFS cycle detection
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int u = temp->vertex;

        if (!visited[u]) {
            if (dfs(u))
                return 1;
        }
        else if (recStack[u]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

// Check if all courses can be finished
int canFinish(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 0; // cycle exists
        }
    }
    return 1; // no cycle
}

int main() {
    int numCourses, E;
    scanf("%d %d", &numCourses, &E);

    // Initialize
    for (int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Input prerequisites
    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // b -> a
        addEdge(b, a);
    }

    if (canFinish(numCourses))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}