#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;
int count = 0;

int empty() {
    return (count == 0);
}

int size() {
    return count;
}

void push_front(int value) {
    if (count == MAX) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = value;
    count++;
}

void push_back(int value) {
    if (count == MAX) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = value;
    count++;
}

void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    count--;
}

void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }

    count--;
}

void get_front() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void get_back() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

void clear() {
    front = rear = -1;
    count = 0;
}

void reverse() {
    if (empty()) return;

    int i = front;
    int j = rear;
    int temp;

    for (int k = 0; k < count / 2; k++) {
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

void sort() {
    if (empty()) return;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            int idx1 = (front + j) % MAX;
            int idx2 = (front + j + 1) % MAX;

            if (deque[idx1] > deque[idx2]) {
                int temp = deque[idx1];
                deque[idx1] = deque[idx2];
                deque[idx2] = temp;
            }
        }
    }
}

void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    for (int k = 0; k < count; k++) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}