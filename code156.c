#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int timeCounter;

// DFS function
void dfs(int u, int parent, int visited[], int disc[], int low[],
         int ap[], int *adj[], int adjSize[]) {

    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    int children = 0;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            children++;
            dfs(v, u, visited, disc, low, ap, adj, adjSize);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Root node case
            if (parent == -1 && children > 1)
                ap[u] = 1;

            // Non-root case
            if (parent != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent) {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int *adj[MAX];
    int adjSize[MAX] = {0};

    // Allocate adjacency list
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int)); // max possible
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int visited[MAX] = {0};
    int disc[MAX], low[MAX];
    int ap[MAX] = {0};

    timeCounter = 0;

    // Handle disconnected graph
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, disc, low, ap, adj, adjSize);
        }
    }

    int found = 0;

    // Print articulation points in sorted order
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("-1");
    }

    printf("\n");

    return 0;
}