#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shop {
    int id;
    char name[50];
    struct shop *next;
};

struct shop *head = NULL;

void addEnd(int id, char name[]) {
    struct shop *n = malloc(sizeof(struct shop));
    n->id = id;
    strcpy(n->name, name);
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    struct shop *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}

void insertAfter(int key, int id, char name[]) {
    struct shop *t = head;
    while (t != NULL && t->id != key)
        t = t->next;

    if (t == NULL) {
        printf("Shop ID not found\n");
        return;
    }

    struct shop *n = malloc(sizeof(struct shop));
    n->id = id;
    strcpy(n->name, name);
    n->next = t->next;
    t->next = n;
}

void removeShop(int id) {
    struct shop *t = head, *p = NULL;

    while (t != NULL && t->id != id) {
        p = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Shop not found\n");
        return;
    }

    if (p == NULL)
        head = t->next;
    else
        p->next = t->next;

    free(t);
}

void searchByName(char name[]) {
    struct shop *t = head;
    while (t != NULL) {
        if (strcmp(t->name, name) == 0) {
            printf("Shop Found: ID=%d Name=%s\n", t->id, t->name);
            return;
        }
        t = t->next;
    }
    printf("Shop not found\n");
}

void display() {
    struct shop *t = head;
    if (t == NULL) {
        printf("No shops available\n");
        return;
    }

    while (t != NULL) {
        printf("ID: %d  Name: %s\n", t->id, t->name);
        t = t->next;
    }
}

int main() {
    int ch, id, key;
    char name[50];

    while (1) {
        printf("\n1.Add End\n2.Insert After ID\n3.Remove Shop\n4.Search by Name\n5.Display\n6.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            scanf("%d %s", &id, name);
            addEnd(id, name);
            break;

        case 2:
            scanf("%d %d %s", &key, &id, name);
            insertAfter(key, id, name);
            break;

        case 3:
            scanf("%d", &id);
            removeShop(id);
            break;

        case 4:
            scanf("%s", name);
            searchByName(name);
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);
        }
    }
}
