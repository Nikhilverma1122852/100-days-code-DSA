#include <stdio.h>
#include <stdlib.h>

// Function to compare for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if cows can be placed with at least 'dist' spacing
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1; // first cow in first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k) return 1;
    }
    return 0;
}

int aggressiveCows(int stalls[], int n, int k) {
    // Sort the stalls
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            result = mid;
            low = mid + 1; // try bigger distance
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, k;

    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    printf("Enter stall positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    int answer = aggressiveCows(stalls, n, k);
    printf("Maximum minimum distance = %d\n", answer);

    return 0;
}