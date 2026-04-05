#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// BFS function
void bfs(int n, int adj[MAX][MAX], int source) {
    int visited[MAX] = {0};

    enqueue(source);
    visited[source] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main() {
    int n, source;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    bfs(n, adj, source);

    return 0;
}