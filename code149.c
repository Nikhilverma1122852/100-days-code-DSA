#include <stdio.h>
#include <stdlib.h>

// Structure for hash map
typedef struct {
    int sum;
    int index;
} HashNode;

int maxLenZeroSum(int arr[], int n) {
    int max_len = 0;
    int prefix_sum = 0;

    // Allocate memory for hash map
    HashNode *hash = (HashNode *)malloc(n * sizeof(HashNode));
    int hash_size = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: If prefix_sum == 0
        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        // Check if prefix_sum already exists
        int found = 0;
        for (int j = 0; j < hash_size; j++) {
            if (hash[j].sum == prefix_sum) {
                int len = i - hash[j].index;
                if (len > max_len)
                    max_len = len;
                found = 1;
                break;
            }
        }

        // If not found, store it
        if (!found) {
            hash[hash_size].sum = prefix_sum;
            hash[hash_size].index = i;
            hash_size++;
        }
    }

    free(hash);
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSum(arr, n);

    printf("Length of longest subarray with sum 0: %d\n", result);

    return 0;
}