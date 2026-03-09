//Given two sorted linked lists, merge them into a single sorted list.
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* createNode(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

struct node* mergeLists(struct node* list1, struct node* list2) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL) tail->next = list1;
    else tail->next = list2;

    return dummy.next;
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    struct node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List1: ");
    display(list1);
    printf("List2: ");
    display(list2);

    struct node* merged = mergeLists(list1, list2);
    printf("Merged List: ");
    display(merged);

    return 0;
}
