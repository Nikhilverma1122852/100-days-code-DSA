#include <stdio.h>

// Function to find Lower Bound (first index >= x)
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // default if not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;  // move left
        } else {
            low = mid + 1;   // move right
        }
    }
    return ans;
}

// Function to find Upper Bound (first index > x)
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // default if not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;  // move left
        } else {
            low = mid + 1;   // move right
        }
    }
    return ans;
}

int main() {
    int n, x;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}