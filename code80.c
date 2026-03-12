#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int temp[n];
    int result[n];
    int stack[n];
    int top = -1;

    printf("Enter temperatures:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp[i]);
        result[i] = 0;   // initialize result
    }

    for(int i = 0; i < n; i++) {

        while(top >= 0 && temp[i] > temp[stack[top]]) {
            int index = stack[top--];
            result[index] = i - index;
        }

        stack[++top] = i;
    }

    printf("Output:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}