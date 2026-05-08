#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find minimum rooms required
int minRooms(int start[], int end[], int n) {

    // Sort both arrays
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0;
    int maxRooms = 0;

    int i = 0, j = 0;

    // Traverse arrays
    while (i < n && j < n) {

        // Need a new room
        if (start[i] < end[j]) {
            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        }
        else {
            // Room becomes free
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {

    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }

    int result = minRooms(start, end, n);

    printf("Minimum rooms required = %d\n", result);

    return 0;
}