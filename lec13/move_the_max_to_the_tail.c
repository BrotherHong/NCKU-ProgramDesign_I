#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->val);
    }
    return 0;
}

//

int find_max() {
    int res = 0;
    for (struct node *cur = head; cur != NULL; cur = cur->next) {
        if (cur->val > res) {
            res = cur->val;
        }
    }
    return res;
}

void MoveToTail() {
    // "struct node *head" and "struct node *tail" are in global
    // you can use this two pointers to do this problem
    int mx = find_max();
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->val != mx) {
        prev = cur;
        cur = cur->next;
    }

    // if at tail
    if (cur->next == NULL) return;

    if (prev == NULL) {
        head = cur->next;
    } else {
        prev->next = cur->next;
    }
    cur->next = NULL;
    tail->next = cur;
    tail = cur;
}