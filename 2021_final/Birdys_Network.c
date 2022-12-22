#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    struct node *next;
};

struct node *read_data(int *size); // TODO: implement this function

void print_data(struct node *adj, int size) {
    if (!adj) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        printf("%d -> ", adj[i].id);
        for (struct node *ptr = adj[i].next; ptr != NULL; ptr = ptr->next) {
            printf("%d ", ptr->id);
        }
        putchar('\n');
    }
    return;
}

void free_data(struct node *adj, int size) {
    if (!adj) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        struct node *ptr = adj[i].next;
        while (ptr) {
            adj[i].next = ptr->next;
            free(ptr);
            ptr = adj[i].next;
        }
    }
    free(adj);
    return;
}

int main() {
    int size;
    struct node *adj = read_data(&size);
    if (!adj) {
        fprintf(stderr, "Error allocating memory.");
        exit(1);
    }
    print_data(adj, size);
    free_data(adj, size);
    return 0;
}

//

void push_back(struct node *head, int val) {
    struct node *p = head;
    while (p->next) p = p->next;

    struct node *new_node = malloc(sizeof(struct node));
    new_node->id = val;
    new_node->next = NULL;

    p->next = new_node;
}

void swap(struct node *a, struct node *b) {
    struct node tmp;
    tmp = *a;
    *a = *b;
    *b =  tmp;
}

struct node *read_data(int *size) {
    struct node *result = malloc(sizeof(struct node) * 1000);
    int sz = 0;
    while (1) {
        int id, val;
        if (scanf("%d -> ", &id) == EOF) break;
        sz++;
        result[sz-1].id = id;
        result[sz-1].next = NULL;
        // ->
        // char trash[5];
        // scanf("%s", trash);
        //
        while (1) {
            scanf("%d", &val);
            // printf("TEST %d\n", val);
            if (val == 0) break;
            push_back(&result[sz-1], val);
        }
    }
    // bubble sort
    for (int i = sz - 1; i > 0; i--) {
        for (int j = 0;j+1 < sz;j++) {
            if (result[j].id > result[j+1].id) {
                swap(&result[j], &result[j+1]);
            }
        }
    }

    // return
    *size = sz;
    return result;
}