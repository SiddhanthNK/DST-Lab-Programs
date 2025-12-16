#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


void insertFront(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertEnd(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertPosition(int value, int pos) {
    if (pos < 1) {
        printf("Position not valid!\n");
        return;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    
    if (pos == 1 || head == NULL) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
        return;
    }

    struct node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position not valid!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, pos);
}


void deleteFront() {
    if (head == NULL)
        printf("List is empty!\n");
    else {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted from front.\n");
    }
}


void deleteEnd() {
    if (head == NULL)
        printf("List is empty!\n");
    else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
        printf("Deleted from end.\n");
    }
}


void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos < 1) {
        printf("Position not valid!\n");
        return;
    }

    
    if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node from position 1.\n");
        return;
    }

    struct node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position not valid!\n");
        return;
    }

    struct node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Deleted node from position %d.\n", pos);
}


void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value, pos;

    while (1) {

        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Front\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteFront();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
