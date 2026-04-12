#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using Quadratic Probing
void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == -1) {
            table[newIndex] = key;
            return;
        }
    }
}

// Search using Quadratic Probing
void search(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[newIndex] == -1) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);   // size of hash table
    scanf("%d", &q);   // number of operations

    init();

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}