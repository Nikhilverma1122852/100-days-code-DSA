#include <stdio.h>
#include <stdlib.h>

void relativeSort(int arr1[], int n, int arr2[], int m) {
    int count[1001] = {0};  // since values are 0–1000

    // Step 1: Count frequency of arr1
    for (int i = 0; i < n; i++) {
        count[arr1[i]]++;
    }

    int result[n];
    int index = 0;

    // Step 2: Place elements as per arr2 order
    for (int i = 0; i < m; i++) {
        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Step 3: Place remaining elements in ascending order
    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            result[index++] = i;
            count[i]--;
        }
    }

    // Copy result back to arr1
    for (int i = 0; i < n; i++) {
        arr1[i] = result[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, m;

    printf("Enter size of arr1: ");
    scanf("%d", &n);
    int arr1[n];

    printf("Enter elements of arr1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of arr2: ");
    scanf("%d", &m);
    int arr2[m];

    printf("Enter elements of arr2:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    relativeSort(arr1, n, arr2, m);

    printf("Sorted array:\n");
    printArray(arr1, n);

    return 0;
}