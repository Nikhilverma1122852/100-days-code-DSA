#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    
    if (head == NULL || head->next == NULL)
        return NULL;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    
    return NULL;
}

int main() {
    int n, pos;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if (n == 0) {
        printf("No cycle\n");
        return 0;
    }

    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;
    struct ListNode *cycleNode = NULL;

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if (i == 0)
            cycleNode = head;
        if (i == pos)
            cycleNode = newNode;
    }

    printf("Enter pos (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos != -1) {
        temp->next = cycleNode;
    }

    struct ListNode *result = detectCycle(head);

    if (result == NULL)
        printf("No cycle\n");
    else
        printf("Cycle starts at node with value: %d\n", result->val);

    return 0;
}