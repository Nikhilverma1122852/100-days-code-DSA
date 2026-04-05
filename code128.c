#include <stdio.h>

#define MAX 100

// Queue structure
typedef struct {
    int x, y;
} Pair;

Pair queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

// Dequeue
Pair dequeue() {
    return queue[front++];
}

// Check if empty
int isEmpty() {
    return front == rear;
}

// Function to calculate minimum time
int orangesRotting(int grid[MAX][MAX], int rows, int cols) {
    int fresh = 0;

    // Directions: up, down, left, right
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    // Initialize queue with rotten oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int minutes = 0;

    // BFS
    while (!isEmpty()) {
        int size = rear - front;
        int infected = 0;

        for (int i = 0; i < size; i++) {
            Pair p = dequeue();

            for (int d = 0; d < 4; d++) {
                int nx = p.x + dir[d][0];
                int ny = p.y + dir[d][1];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                    infected = 1;
                }
            }
        }

        if (infected) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}

// Main function
int main() {
    int rows, cols;
    int grid[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter grid values (0,1,2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, rows, cols);

    printf("Minimum minutes: %d\n", result);

    return 0;
}