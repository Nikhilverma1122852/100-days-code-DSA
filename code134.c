#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

// Queue structure
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int main() {
    int numCourses, prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &prerequisitesSize);

    int prerequisites[prerequisitesSize][2];

    printf("Enter prerequisite pairs (ai bi):\n");
    for (int i = 0; i < prerequisitesSize; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    // Graph representation
    int graph[MAX][MAX];
    int graphColSize[MAX] = {0};
    int indegree[MAX] = {0};

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphColSize[b]++] = a;
        indegree[a]++;
    }

    Queue q;
    initQueue(&q);

    // Push nodes with indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int result[MAX];
    int index = 0;

    // BFS (Topological Sort)
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        result[index++] = node;

        for (int i = 0; i < graphColSize[node]; i++) {
            int neighbor = graph[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                enqueue(&q, neighbor);
            }
        }
    }

    // Output result
    if (index != numCourses) {
        printf("[] (Cycle detected, no valid ordering)\n");
    } else {
        printf("Course Order: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}