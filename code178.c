#include <stdio.h>

// Check if shipping is possible within given days
int canShip(int weights[], int n, int days, int capacity) {
    int currentWeight = 0;
    int requiredDays = 1;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
        } else {
            requiredDays++;
            currentWeight = weights[i];

            if (requiredDays > days)
                return 0;
        }
    }
    return 1;
}

// Binary search to find minimum capacity
int shipWithinDays(int weights[], int n, int days) {
    int maxWeight = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] > maxWeight)
            maxWeight = weights[i];
        sum += weights[i];
    }

    int low = maxWeight, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canShip(weights, n, days, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller capacity
        } else {
            low = mid + 1;   // increase capacity
        }
    }

    return ans;
}

int main() {
    int n, days;

    printf("Enter number of packages: ");
    scanf("%d", &n);

    int weights[n];

    printf("Enter weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter number of days: ");
    scanf("%d", &days);

    int result = shipWithinDays(weights, n, days);

    printf("Minimum ship capacity: %d\n", result);

    return 0;
}