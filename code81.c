#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        return -1;   // Queue empty
    }

    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') {   // enqueue
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (op[0] == 'd') {  // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}