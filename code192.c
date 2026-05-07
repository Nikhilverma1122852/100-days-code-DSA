#include <stdio.h>
#include <stdlib.h>

int merge(int nums[], int temp[], int left, int mid, int right) {
    int count = 0;

    // Count reverse pairs
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge two sorted halves
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy back to original array
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

int mergeSort(int nums[], int temp[], int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int count = 0;

    count += mergeSort(nums, temp, left, mid);
    count += mergeSort(nums, temp, mid + 1, right);

    count += merge(nums, temp, left, mid, right);

    return count;
}

int reversePairs(int nums[], int n) {
    int *temp = (int *)malloc(sizeof(int) * n);

    int result = mergeSort(nums, temp, 0, n - 1);

    free(temp);

    return result;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int ans = reversePairs(nums, n);

    printf("Number of reverse pairs = %d\n", ans);

    return 0;
}