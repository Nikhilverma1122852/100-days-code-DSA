#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Push element to queue
void push(int x) {
    stack1[++top1] = x;
}

// Move elements from stack1 to stack2
void transfer() {
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }
}

// Pop element from queue
int pop() {
    if (top2 == -1) {
        transfer();
    }
    return stack2[top2--];
}

// Peek front element
int peek() {
    if (top2 == -1) {
        transfer();
    }
    return stack2[top2];
}

// Check if queue is empty
bool empty() {
    return (top1 == -1 && top2 == -1);
}

int main() {
    push(1);
    push(2);

    printf("Peek: %d\n", peek());   // 1
    printf("Pop: %d\n", pop());     // 1

    if (empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}