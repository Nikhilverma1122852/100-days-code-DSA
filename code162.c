#include <stdio.h>
#include <limits.h>

#define MAX 105
#define INF 1000000000

int findTheCity(int n, int dist[MAX][MAX], int distanceThreshold) {
    // Floyd–Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int city = -1;
    int minCount = INT_MAX;

    // Count reachable cities
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // If tie, choose greater index
        if (count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    return city;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int dist[MAX][MAX];

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        dist[u][v] = w;
        dist[v][u] = w;
    }

    int distanceThreshold;
    scanf("%d", &distanceThreshold);

    int result = findTheCity(n, dist, distanceThreshold);
    printf("%d\n", result);

    return 0;
}