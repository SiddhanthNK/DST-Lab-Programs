#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    int value;
    struct node *newNode, *temp;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void insertLeft(int value, int key) {
    struct node *temp = head, *newNode;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;
}

void deleteByValue(int key) {
    struct node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, value, key;

    while (1) {
        printf("\n1.Create\n2.Insert Left\n3.Delete by Value\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                scanf("%d %d", &value, &key);
                insertLeft(value, key);
                break;

            case 3:
                scanf("%d", &key);
                deleteByValue(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);
        }
    }
}
