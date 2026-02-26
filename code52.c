#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;


MyLinkedList* createList() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}


int get(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* temp = obj->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->val;
}


void addAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void addAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* temp = obj->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    obj->size++;
}

void addAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        addAtHead(obj, val);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;

    Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    obj->size++;
}

void deleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp = obj->head;

    if (index == 0) {
        obj->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        free(deleteNode);
    }

    obj->size--;
}


void printList(MyLinkedList* obj) {
    Node* temp = obj->head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}


void freeList(MyLinkedList* obj) {
    Node* temp = obj->head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(obj);
}


int main() {
    MyLinkedList* list = createList();

    addAtHead(list, 1);
    addAtTail(list, 3);
    addAtIndex(list, 1, 2);  
    printList(list);

    printf("Value at index 1: %d\n", get(list, 1)); 

    deleteAtIndex(list, 1);  
    printList(list);

    printf("Value at index 1: %d\n", get(list, 1));  

    freeList(list);
    return 0;
}