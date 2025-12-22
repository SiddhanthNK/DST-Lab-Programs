#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct staff {
    int id;
    char name[50];
    char dept[20];
    struct staff *next;
};

struct staff *head = NULL;

void addBegin(int id, char name[], char dept[]) {
    struct staff *n = malloc(sizeof(struct staff));
    n->id = id;
    strcpy(n->name, name);
    strcpy(n->dept, dept);
    n->next = head;
    head = n;
}

void addEnd(int id, char name[], char dept[]) {
    struct staff *n = malloc(sizeof(struct staff));
    n->id = id;
    strcpy(n->name, name);
    strcpy(n->dept, dept);
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    struct staff *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}

void insertPos(int pos, int id, char name[], char dept[]) {
    if (pos <= 1) {
        addBegin(id, name, dept);
        return;
    }

    struct staff *t = head;
    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct staff *n = malloc(sizeof(struct staff));
    n->id = id;
    strcpy(n->name, name);
    strcpy(n->dept, dept);
    n->next = t->next;
    t->next = n;
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct staff *t = head;

    if (pos == 1) {
        head = head->next;
        free(t);
        return;
    }

    struct staff *p = NULL;
    for (int i = 1; i < pos && t != NULL; i++) {
        p = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Invalid position\n");
        return;
    }

    p->next = t->next;
    free(t);
}

void search() {
    int ch, id;
    char name[50];
    struct staff *t = head;

    printf("1.Search by ID\n2.Search by Name\n");
    scanf("%d", &ch);

    if (ch == 1) {
        scanf("%d", &id);
        while (t != NULL) {
            if (t->id == id) {
                printf("Found: %d %s %s\n", t->id, t->name, t->dept);
                return;
            }
            t = t->next;
        }
    } else {
        scanf("%s", name);
        while (t != NULL) {
            if (strcmp(t->name, name) == 0) {
                printf("Found: %d %s %s\n", t->id, t->name, t->dept);
                return;
            }
            t = t->next;
        }
    }
    printf("Staff not found\n");
}

void display() {
    struct staff *t = head;
    if (t == NULL) {
        printf("No staff available\n");
        return;
    }

    while (t != NULL) {
        printf("ID:%d Name:%s Dept:%s\n", t->id, t->name, t->dept);
        t = t->next;
    }
}

int main() {
    int ch, id, pos;
    char name[50], dept[20];

    while (1) {
        printf("\n1.Add Begin\n2.Add End\n3.Insert Position\n4.Delete Position\n5.Search\n6.Display\n7.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            scanf("%d %s %s", &id, name, dept);
            addBegin(id, name, dept);
            break;

        case 2:
            scanf("%d %s %s", &id, name, dept);
            addEnd(id, name, dept);
            break;

        case 3:
            scanf("%d %d %s %s", &pos, &id, name, dept);
            insertPos(pos, id, name, dept);
            break;

        case 4:
            scanf("%d", &pos);
            deletePos(pos);
            break;

        case 5:
            search();
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);
        }
    }
}
