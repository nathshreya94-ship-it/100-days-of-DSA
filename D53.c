#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for BFS
struct Pair {
    struct Node* node;
    int hd;
};

struct Pair queue[MAX];
int front = 0, rear = 0;

// Create Node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert level order
struct Node* insertLevelOrder(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = insertLevelOrder(arr, n, 2*i + 1);
    root->right = insertLevelOrder(arr, n, 2*i + 2);

    return root;
}

// Map using arrays
int map[MAX][MAX];   // store nodes
int count[MAX];      // count per HD
int minHD = 0, maxHD = 0;

// Vertical Order Function
void verticalOrder(struct Node* root) {
    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        map[hd + 50][count[hd + 50]++] = curr->data;

        if (curr->left)
            queue[rear++] = (struct Pair){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct Pair){curr->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i + 50]; j++) {
            printf("%d ", map[i + 50][j]);
        }
        printf("\n");
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = insertLevelOrder(arr, n, 0);

    verticalOrder(root);

    return 0;
}