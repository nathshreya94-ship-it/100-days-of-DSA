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

int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("0");
        return 0;
    }

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[N];

    for (int i = 0; i < N; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < N; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < N)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < N)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    printf("%d", countLeaves(nodes[0]));

    return 0;
}