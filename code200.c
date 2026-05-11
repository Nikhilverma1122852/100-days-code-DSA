// Count of Smaller Numbers After Self
// VS Code Compatible C Program

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int counts[]) {

    int size = right - left + 1;

    Pair *temp = (Pair *)malloc(size * sizeof(Pair));

    int i = left;
    int j = mid + 1;
    int k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {

        if (arr[i].val <= arr[j].val) {
            counts[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        counts[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

void mergeSort(Pair arr[], int left, int right, int counts[]) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, counts);
    mergeSort(arr, mid + 1, right, counts);

    merge(arr, left, mid, right, counts);
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    Pair arr[n];
    int counts[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);

        arr[i].val = nums[i];
        arr[i].idx = i;

        counts[i] = 0;
    }

    mergeSort(arr, 0, n - 1, counts);

    printf("Counts of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", counts[i]);
    }

    printf("\n");

    return 0;
}