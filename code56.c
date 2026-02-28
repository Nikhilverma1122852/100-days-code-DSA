#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *nextNode = NULL;

    while (head != NULL) {
        nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);

    struct ListNode* firstHalf = head;
    struct ListNode* secondHalf = slow;

    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty\n");
        return 0;
    }

    int value;
    struct ListNode *head = NULL, *temp = NULL;

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct ListNode* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    if (isPalindrome(head))
        printf("Output: true\n");
    else
        printf("Output: false\n");

    return 0;
}