#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, i;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    int arr1[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[m];
    for (i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    for (i = 0; i < n; i++)
        insertEnd(&head1, arr1[i]);

    int intersectValue = -1;
    for (i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr2[i] == arr1[j]) {
                intersectValue = arr2[i];
                break;
            }
        }
        if (intersectValue != -1)
            break;
    }

    struct Node* temp1 = head1;
    struct Node* intersectionNode = NULL;

    if (intersectValue != -1) {
        while (temp1 != NULL) {
            if (temp1->data == intersectValue) {
                intersectionNode = temp1;
                break;
            }
            temp1 = temp1->next;
        }
    }

    for (i = 0; i < m; i++) {
        if (arr2[i] == intersectValue)
            break;
        insertEnd(&head2, arr2[i]);
    }

    if (intersectionNode != NULL) {
        if (head2 == NULL)
            head2 = intersectionNode;
        else {
            struct Node* temp2 = head2;
            while (temp2->next != NULL)
                temp2 = temp2->next;
            temp2->next = intersectionNode;
        }
    }

    struct Node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}