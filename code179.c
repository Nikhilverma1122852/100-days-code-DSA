#include <stdio.h>

// Function to check if boards can be painted within maxTime using k painters
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currentSum + boards[i] <= maxTime) {
            currentSum += boards[i];
        } else {
            painters++;
            currentSum = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int max = boards[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > max)
            max = boards[i];
        sum += boards[i];
    }

    int low = max, high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // need more time
        }
    }

    return result;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int result = minTime(boards, n, k);

    printf("Minimum time required: %d\n", result);

    return 0;
}