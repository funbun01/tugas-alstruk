#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = (*head)->prev;
    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("Address: %p, Data: %d\n", (void*)temp, temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void sortList(Node** head) {
    if (*head == NULL) return;
    Node* start = *head;
    Node* curr = NULL;
    Node* index = NULL;

    for (curr = start; curr->next != start; curr = curr->next) {
        for (index = curr->next; index != start; index = index->next) {
            if (curr->data > index->data) {
                int tempData = curr->data;
                curr->data = index->data;
                index->data = tempData;
            }
        }
    }
}

int main() {
    int N, data;
    Node* head = NULL;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf(" \n");
    printList(head);

    sortList(&head);

    printf(" \n");
    printList(head);

    return 0;
}