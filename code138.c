#include <stdio.h>
#include <limits.h>

#define MAX 101

int main() {
    int n, m, k;

    // Input number of nodes, edges
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    // Input source node
    printf("Enter source node k: ");
    scanf("%d", &k);

    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;

    // Dijkstra Algorithm
    for (int i = 1; i <= n; i++) {
        int u = -1;

        // Find minimum distance unvisited node
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INT_MAX) break;

        visited[u] = 1;

        // Relax edges
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Find answer
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("Output: -1\n");
            return 0;
        }
        if (dist[i] > maxTime) {
            maxTime = dist[i];
        }
    }

    printf("Output: %d\n", maxTime);

    return 0;
}