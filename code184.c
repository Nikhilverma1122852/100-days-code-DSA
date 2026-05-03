#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition (Lomuto)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// Quickselect
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k)
            return arr[pi];
        else if (pi < k)
            return quickSelect(arr, pi + 1, high, k);
        else
            return quickSelect(arr, low, pi - 1, k);
    }
    return -1;
}

// Find kth largest
int findKthLargest(int arr[], int n, int k) {
    int target = n - k; // convert to index
    return quickSelect(arr, 0, n - 1, target);
}

// Main function (VS Code execution)
int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = findKthLargest(arr, n, k);

    printf("Kth largest element = %d\n", result);

    return 0;
}