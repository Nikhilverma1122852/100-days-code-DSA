#include <stdio.h>

// Function to calculate total hours needed at speed k
long long calculateHours(int piles[], int n, int k) {
    long long hours = 0;

    for(int i = 0; i < n; i++) {
        // ceil(piles[i] / k)
        hours += (piles[i] + k - 1) / k;
    }

    return hours;
}

// Function to find minimum eating speed
int minEatingSpeed(int piles[], int n, int h) {
    int left = 1;
    int right = piles[0];

    // Find maximum pile (upper bound)
    for(int i = 1; i < n; i++) {
        if(piles[i] > right) {
            right = piles[i];
        }
    }

    int ans = right;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        long long hours = calculateHours(piles, n, mid);

        if(hours <= h) {
            ans = mid;
            right = mid - 1;  // try smaller k
        } else {
            left = mid + 1;  // increase speed
        }
    }

    return ans;
}

int main() {
    int n, h;

    // Input number of piles
    printf("Enter number of piles: ");
    scanf("%d", &n);

    int piles[n];

    // Input piles
    printf("Enter bananas in each pile: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }

    // Input hours
    printf("Enter total hours (h): ");
    scanf("%d", &h);

    // Function call
    int result = minEatingSpeed(piles, n, h);

    printf("Minimum eating speed (k): %d\n", result);

    return 0;
}