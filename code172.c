#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Avoid overflow
        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x;

    printf("Enter a non-negative integer: ");
    scanf("%d", &x);

    int result = mySqrt(x);

    printf("Square root (floor value): %d\n", result);

    return 0;
}