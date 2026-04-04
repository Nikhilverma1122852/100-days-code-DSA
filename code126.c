#include <stdio.h>

#define MAX 50

// DFS function
void dfs(int image[MAX][MAX], int m, int n, int r, int c, int originalColor, int newColor) {
    // Boundary check
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // If current pixel is not original color, stop
    if (image[r][c] != originalColor)
        return;

    // Change color
    image[r][c] = newColor;

    // Visit 4 directions
    dfs(image, m, n, r + 1, c, originalColor, newColor); // down
    dfs(image, m, n, r - 1, c, originalColor, newColor); // up
    dfs(image, m, n, r, c + 1, originalColor, newColor); // right
    dfs(image, m, n, r, c - 1, originalColor, newColor); // left
}

int main() {
    int m, n;
    int image[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the image matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;
    printf("Enter starting row, column and new color: ");
    scanf("%d %d %d", &sr, &sc, &color);

    int originalColor = image[sr][sc];

    // If new color is same as original, no change
    if (originalColor != color) {
        dfs(image, m, n, sr, sc, originalColor, color);
    }

    printf("Flood Filled Image:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}