#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define MAX 100

int table[MAX];
int m;

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table full\n");
}

// Search using quadratic probing
int search(int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == EMPTY)
            return 0;

        i++;
    }
    return 0;
}

int main() {
    int q;
    char op[10];
    int key;

    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}