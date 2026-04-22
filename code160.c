#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Adjacency list node
struct Node {
    int v;
    struct Node* next;
};

// Graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Stack
int stack[MAX], top = -1;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(struct Graph* g, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// DFS 1 (fill stack)
void dfs1(int u, struct Graph* g, int visited[]) {
    visited[u] = 1;

    struct Node* temp = g->adj[u];
    while (temp) {
        if (!visited[temp->v])
            dfs1(temp->v, g, visited);
        temp = temp->next;
    }

    push(u);
}

// DFS 2 (on transpose)
void dfs2(int u, struct Graph* gT, int visited[]) {
    visited[u] = 1;

    struct Node* temp = gT->adj[u];
    while (temp) {
        if (!visited[temp->v])
            dfs2(temp->v, gT, visited);
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph g, gT;
    g.V = gT.V = V;

    // Initialize adjacency lists
    for (int i = 0; i < V; i++) {
        g.adj[i] = NULL;
        gT.adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
        addEdge(&gT, v, u); // transpose
    }

    int visited[MAX] = {0};

    // Step 1: DFS and fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, &g, visited);
        }
    }

    // Reset visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Step 2 & 3: Process stack on transpose graph
    int scc = 0;

    while (top != -1) {
        int node = pop();
        if (!visited[node]) {
            dfs2(node, &gT, visited);
            scc++;
        }
    }

    printf("%d\n", scc);

    return 0;
}