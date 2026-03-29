#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create Node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert Level Order
struct Node* insertLevelOrder(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = insertLevelOrder(arr, n, 2*i + 1);
    root->right = insertLevelOrder(arr, n, 2*i + 2);

    return root;
}

// Check Mirror
int isMirror(struct Node* left, struct Node* right) {
    if (!left && !right) return 1;
    if (!left || !right) return 0;

    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check Symmetric
int isSymmetric(struct Node* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = insertLevelOrder(arr, n, 0);

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}