#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* mergeLists(struct node* head1, struct node* head2) {
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if(head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

void printList(struct node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node* head1 = createList(n);

    scanf("%d", &m);
    struct node* head2 = createList(m);

    struct node* mergedHead = mergeLists(head1, head2);

    printList(mergedHead);

    return 0;
}