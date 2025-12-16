#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head2 = NULL;

void insertFront(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertFront2(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head2;
    head2 = newNode;
}

void display(struct node *temp) {
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList() {
    if (head == NULL || head->next == NULL) {
        printf("List too short to sort\n");
        return;
    }
    struct node *i, *j;
    int t;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
    printf("List sorted\n");
}

void reverseList() {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed\n");
}

void concatenateLists() {
    if (head == NULL) {
        head = head2;
        head2 = NULL;
        printf("Concatenation done\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2 = NULL;
    printf("Concatenation done\n");
}

void deleteByKey(int key) {
    struct node *temp = head;
    struct node *prev = NULL;

    if (temp == NULL) {
        printf("List empty\n");
        return;
    }

    if (temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Deleted %d\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d\n", key);
}

int main() {
    int choice, value, n, key;

    while (1) {
        printf("\n1.Insert List1\n2.Insert List2\n3.Display List1\n4.Display List2\n5.Sort\n6.Reverse\n7.Concatenate\n8.Delete by Key\n9.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &n);
                while (n--) {
                    scanf("%d", &value);
                    insertFront(value);
                }
                break;

            case 2:
                scanf("%d", &n);
                while (n--) {
                    scanf("%d", &value);
                    insertFront2(value);
                }
                break;

            case 3:
                display(head);
                break;

            case 4:
                display(head2);
                break;

            case 5:
                sortList();
                break;

            case 6:
                reverseList();
                break;

            case 7:
                concatenateLists();
                break;

            case 8:
                scanf("%d", &key);
                deleteByKey(key);
                break;

            case 9:
                exit(0);
        }
    }

    return 0;
}
