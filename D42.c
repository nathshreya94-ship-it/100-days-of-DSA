#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;
int size = 0;

int stack[MAX];
int top = -1;

void enqueue(int value) {
    queue[++rear] = value;
    size++;
}

int dequeue() {
    size--;
    return queue[front++];
}

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }

    while (size > 0) {
        push(dequeue());
    }

    while (top >= 0) {
        enqueue(pop());
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}