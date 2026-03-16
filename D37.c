#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size < MAX) {
        pq[size++] = x;
    }
}

// Find index of smallest element
int findMinIndex() {
    if (size == 0)
        return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete highest priority element (smallest value)
void deleteElement() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek highest priority element
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {
    int N;
    scanf("%d", &N);

    char operation[10];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        }
        else if (strcmp(operation, "delete") == 0) {
            deleteElement();
        }
        else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }

    return 0;
}