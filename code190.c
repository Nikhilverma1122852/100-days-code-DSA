// Maximum Gap using Bucket Sort
// VS Code Compatible Program

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int arr[], int n) {

    // If array has less than 2 elements
    if (n < 2)
        return 0;

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    // Find minimum and maximum element
    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];

        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // If all elements are same
    if (minVal == maxVal)
        return 0;

    // Calculate bucket size
    int bucketSize = (maxVal - minVal) / (n - 1);

    if (bucketSize == 0)
        bucketSize = 1;

    // Calculate number of buckets
    int bucketCount = ((maxVal - minVal) / bucketSize) + 1;

    // Create buckets
    int *bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int *bucketMax = (int*)malloc(bucketCount * sizeof(int));
    int *used = (int*)calloc(bucketCount, sizeof(int));

    // Initialize buckets
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++) {

        int idx = (arr[i] - minVal) / bucketSize;

        if (arr[i] < bucketMin[idx])
            bucketMin[idx] = arr[i];

        if (arr[i] > bucketMax[idx])
            bucketMax[idx] = arr[i];

        used[idx] = 1;
    }

    // Find maximum gap
    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {

        if (!used[i])
            continue;

        int gap = bucketMin[i] - prevMax;

        if (gap > maxGap)
            maxGap = gap;

        prevMax = bucketMax[i];
    }

    // Free memory
    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maximumGap(arr, n);

    printf("\nMaximum Gap = %d\n", result);

    return 0;
}