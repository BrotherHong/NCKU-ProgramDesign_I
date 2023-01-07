#include <stdio.h>
#include <stdlib.h>

// Enumrations
enum orb_type {
    O_UNSET = -1,
    O_RED = 17, O_BLUE = 1, O_GREEN = 6, O_YELLOW = 24,
    O_FLOAT = 5, O_CLONE = 2, O_EXPAND = 4, O_DYSON = 3
};

// Structure Declairation
struct node_t {
    struct node_t *next;
    enum orb_type orb;
};

struct head_t {
    struct node_t *head;
    int count;
    enum orb_type orb;
};

// Function Prototypes
struct head_t *alloc_list_heads(int size);              // Allocate memory for array of list heads
void init_head_arr(struct head_t *arr, int size);       // Initialize array of linked-lists
void print_magic_circle(struct head_t *arr, int size);  // Print the structure of magic circle
void insert_next(struct head_t *arr, int size, const char c);  // Insert the next orb onto the magic circle

// Main Function
int main() {
    int size;       // Size of center ring
    int count;      // Number of stem orbs will be put;

    // Allocate ring
    scanf("%d%d%*c", &size, &count);
    struct head_t *center_ring = alloc_list_heads(size);

    // Read and set ring
    init_head_arr(center_ring, size);

    // Place the orbs
    for (int i = 0; i < count; ++i) {
        insert_next(center_ring, size, getchar());
    }

    // Print magic circle configuration
    print_magic_circle(center_ring, size);
    return 0;
}

// Function Definitions
void print_magic_circle(struct head_t *arr, int size) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        // Print center orb
        printf("CO_%c", arr[i].orb + 'A');

        // Print stem
        struct node_t *cur = arr[i].head;
        while (cur) {
            printf(" -> %c", 'A' + cur->orb);
            cur = cur->next;
        }
        if (i + 1 < size) putchar('\n');
    }
    return;
}

// TODO

// Allocate memory for array of list heads
struct head_t *alloc_list_heads(int size) {
    return malloc(sizeof(struct head_t) * size);
}

// Read input and Initialize array of linked-lists
void init_head_arr(struct head_t *arr, int size) {

    for (int i = 0;i < size;i++) {
        arr[i].head = NULL;
        arr[i].count = 0;
        arr[i].orb = getchar() - 'A';
    }
    getchar(); // READ '\n'
    return;
}

// global var
int curRoot = 0;

// function definition
// push
void push_normal_orb(struct node_t **head_p, const enum orb_type orb);
void push_float_orb(struct node_t **head_p);
void push_clone_orb(struct node_t **head_p, struct head_t *arr, int size);
void push_expand_orb(struct node_t **head_p, struct head_t *arr, int size);
void push_dyson_orb(struct node_t **head_p, struct head_t *arr, int size);
// support
struct node_t *new_node(const enum orb_type orb);
int count_clone_orb(struct node_t *head);
void clear_stem(struct node_t **head_p);
struct node_t *clone_stem(struct node_t *head);
int count_and_delete_orb(struct node_t **head_p, const enum orb_type type);
//

// Insert the next orb onto the magic circle
void insert_next(struct head_t *arr, int size, const char c) {
    enum orb_type orb = c - 'A';
    struct node_t **head_p = &arr[curRoot].head;
    switch (orb) {
        case O_BLUE: case O_RED: case O_GREEN: case O_YELLOW:
            push_normal_orb(head_p, orb);
            break;
        case O_FLOAT:
            push_float_orb(head_p);
            break;
        case O_CLONE:
            push_clone_orb(head_p, arr, size);
            break;
        case O_EXPAND:
            push_expand_orb(head_p, arr, size);
            break;
        case O_DYSON:
            push_dyson_orb(head_p, arr, size);
            break;
    }
    // go to next root
    curRoot = (curRoot + 1) % size;
    return;
}

void push_normal_orb(struct node_t **head_p, const enum orb_type orb) {
    struct node_t *node = new_node(orb);
    struct node_t *head = *head_p;

    if (head == NULL) {
        *head_p = node;
        return;
    }

    struct node_t *tail = head;
    while (tail->next) tail = tail->next;
    
    if (tail->orb == O_FLOAT) {
        // push front
        node->next = head;
        *head_p = node;
    } else {
        // push back
        tail->next = node;
    }

}

void push_float_orb(struct node_t **head_p) {
    struct node_t *head = *head_p;
    if (head != NULL) {
        struct node_t *tail = head;
        while (tail->next) tail = tail->next;

        if (tail->orb == O_FLOAT) return;
    }

    push_normal_orb(head_p, O_FLOAT);
}

void push_clone_orb(struct node_t **head_p, struct head_t *arr, int size) {
    push_normal_orb(head_p, O_CLONE);
    struct node_t *head = *head_p;

    int k = 0;
    for (int i = 0;i < size;i++) {
        k += count_clone_orb(arr[i].head);
    }

    int target = curRoot - k;
    while (target < 0) target += size;

    if (target == curRoot) return;

    clear_stem(&arr[target].head);
    arr[target].head = clone_stem(head);
}

void push_expand_orb(struct node_t **head_p, struct head_t *arr, int size) {
    push_normal_orb(head_p, O_EXPAND);

    for (int i = 0;i < size;i++) {
        push_normal_orb(&arr[i].head, arr[curRoot].orb);
    }
}

void push_dyson_orb(struct node_t **head_p, struct head_t *arr, int size) {
    push_normal_orb(head_p, O_DYSON);

    int cnt = 0;
    const enum orb_type targetOrb = arr[curRoot].orb;

    for (int i = 0;i < size;i++) {
        if (i == curRoot) continue;
        cnt += count_and_delete_orb(&arr[i].head, targetOrb);
    }

    while (cnt--) {
        push_normal_orb(head_p, targetOrb);
    }
}

//

struct node_t *new_node(const enum orb_type orb) {
    struct node_t *node = malloc(sizeof(struct node_t));
    node->next = NULL;
    node->orb = orb;
    return node;
}

int count_clone_orb(struct node_t *head) {
    int cnt = 0;
    struct node_t *cur = head;
    while (cur) {
        if (cur->orb == O_CLONE) {
            cnt++;
        }
        cur = cur->next;
    }
    return cnt;
}

void clear_stem(struct node_t **head_p) {
    struct node_t *cur = *head_p;
    struct node_t *next;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *head_p = NULL;
}

struct node_t *clone_stem(struct node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node_t *clone = new_node(head->orb);
    struct node_t *p = clone;
    while (head->next) {
        head = head->next;
        p->next = new_node(head->orb);
        p = p->next;
    }
    return clone;
}

int count_and_delete_orb(struct node_t **head_p, const enum orb_type type) {
    int cnt = 0;
    struct node_t *head = *head_p;
    struct node_t *cur = head;

    int n = 0;
    while (cur) {
        n++;
        cur = cur->next;
    }

    if (n == 0) return 0;

    enum orb_type *orbs = malloc(sizeof(enum orb_type) * n);
    int idx = 0;
    cur = head;
    while (cur) {
        if (cur->orb == type) {
            cnt++;
        } else {
            orbs[idx++] = cur->orb;
        }
        cur = cur->next;
    }

    clear_stem(head_p);

    if (idx > 0) {
        *head_p = new_node(orbs[0]);
        cur = *head_p;
        for (int i = 1;i < idx;i++) {
            cur->next = new_node(orbs[i]);
            cur = cur->next;
        }
    }

    free(orbs);
    return cnt;
}
