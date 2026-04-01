#include <stdio.h>
#include <stdlib.h>

// Function to check Min-Heap property
int isMinHeap(int arr[], int n) {
    // Check for all parent nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Left child index = 2*i + 1
        // Right child index = 2*i + 2
        
        if (arr[i] > arr[2 * i + 1])
            return 0;

        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            return 0;
    }
    return 1;
}

int main() {
    int n;

    // Input number of nodes
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // Input level order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap
    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    free(arr);
    return 0;
}