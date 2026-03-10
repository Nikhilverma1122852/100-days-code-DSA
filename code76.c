#include <stdio.h>
#include <stdlib.h>

void maxSlidingWindow(int nums[], int n, int k) {
    
    int *deque = (int *)malloc(n * sizeof(int));
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {

        // Remove elements outside window
        if (front <= rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements
        while (front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        // Add current index
        deque[++rear] = i;

        // Print maximum when window size reached
        if (i >= k - 1)
            printf("%d ", nums[deque[front]]);
    }

    free(deque);
}

int main() {

    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter window size k: ");
    scanf("%d", &k);

    printf("Sliding Window Maximum: ");
    maxSlidingWindow(nums, n, k);

    return 0;
}