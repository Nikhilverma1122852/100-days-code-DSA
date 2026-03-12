#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

// Compare function for sorting by frequency (descending)
int compare(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return p2->freq - p1->freq;
}

int main() {

    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    int freq[20001] = {0};
    int offset = 10000;

    // Count frequency
    for(int i = 0; i < n; i++)
        freq[nums[i] + offset]++;

    Pair arr[20001];
    int size = 0;

    // Store numbers with frequency
    for(int i = 0; i < 20001; i++) {
        if(freq[i] > 0) {
            arr[size].num = i - offset;
            arr[size].freq = freq[i];
            size++;
        }
    }

    // Sort by frequency
    qsort(arr, size, sizeof(Pair), compare);

    printf("Top %d frequent elements:\n", k);

    for(int i = 0; i < k; i++)
        printf("%d ", arr[i].num);

    return 0;
}