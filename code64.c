#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int minStack[MAX];
int top = -1;
int minTop = -1;

void push(int val) {
    top++;
    stack[top] = val;

    if (minTop == -1 || val <= minStack[minTop]) {
        minStack[++minTop] = val;
    }
}

void pop() {
    if (stack[top] == minStack[minTop]) {
        minTop--;
    }
    top--;
}

int getTop() {
    return stack[top];
}

int getMin() {
    return minStack[minTop];
}

int main() {
    push(-2);
    push(0);
    push(-3);

    printf("Minimum: %d\n", getMin()); // -3

    pop();

    printf("Top: %d\n", getTop());     // 0
    printf("Minimum: %d\n", getMin()); // -2

    return 0;
}