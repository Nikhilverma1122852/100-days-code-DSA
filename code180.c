#include <stdio.h>

// Check if we can split into k subarrays with max sum <= maxSum
int canSplit(int nums[], int n, int k, int maxSum) {
    int count = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            count++;
            currentSum = nums[i];

            if (count > k)
                return 0;
        }
    }
    return 1;
}

// Function to find minimized largest sum
int splitArray(int nums[], int n, int k) {
    int max = nums[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > max)
            max = nums[i];
        sum += nums[i];
    }

    int low = max, high = sum, result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSplit(nums, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller answer
        } else {
            low = mid + 1;   // need bigger sum
        }
    }

    return result;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = splitArray(nums, n, k);

    printf("Minimum largest subarray sum: %d\n", result);

    return 0;
}