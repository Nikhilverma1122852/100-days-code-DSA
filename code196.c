// Merge Intervals - VS Code Version

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator function for sorting
int compare(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;

    return x->start - y->start;
}

void mergeIntervals(Interval arr[], int n) {

    // Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++) {

        // Check overlap
        if (arr[i].start <= result[index].end) {

            // Update ending time
            if (arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }
        }
        else {
            // Add new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("\nMerged Intervals:\n");

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
}

int main() {

    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter intervals (start end):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}