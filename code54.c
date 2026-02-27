#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int val) {
    struct Node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void createLoop(struct Node* head, int pos) {
    if (pos == -1) return;

    struct Node* loopNode = NULL;
    struct Node* temp = head;
    int count = 0;

    while (temp->next != NULL) {
        if (count == pos)
            loopNode = temp;
        temp = temp->next;
        count++;
    }

    temp->next = loopNode;  
}

bool removeLoop(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return false;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;

    return true;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 4);

    createLoop(head, 1);

    bool result = removeLoop(head);

    if (result)
        printf("true\n");
    else
        printf("false\n");

    printf("Linked List after removing loop: ");
    printList(head);

    return 0;
}