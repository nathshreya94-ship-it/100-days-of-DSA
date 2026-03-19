#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* queue[1000];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 999) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    front = rear = -1;  
    struct Node* root = buildTree(arr, n);

    front = rear = -1;  
    levelOrder(root);

    return 0;
}