#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *head = NULL;

void InsertAtHead(int data) {
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void InsertAtPosition(int data, int n) {
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL || n == 1) {
        temp->next = head;
        head = temp;
        return;
    }
    Node *cur = head;
    for(int i = 0; i < n-2; i++) {
        if(cur->next == NULL) break;
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
    return;
}

void DeleteAtPosition(int n) {
    if(head == NULL || n <= 0) return;

    if(n == 1) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
        Node *temp;
        Node *cur = head;
        for(int i = 0; i < n-2; i++) {
            if(cur->next == NULL) return;
            cur = cur->next;
        }
        temp = cur->next;
        if(temp == NULL) return;
        cur->next = temp->next;
        free(temp);
}

void PrintList() {
    if(head == NULL) {
        printf("There is no LinkedList\n");
        return;
    }
    Node *cur = head;
    while(cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void FreeList() {
    Node *cur = head;
    while(cur) {
        Node *temp = cur;
        cur = cur->next;
        free(temp);
    }
    return;
}

int main() {
    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);
    InsertAtPosition(5, 2);
    InsertAtPosition(7, 1);

    DeleteAtPosition(3);

    PrintList();

    FreeList();

    return 0;
}