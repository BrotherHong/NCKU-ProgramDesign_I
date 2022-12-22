#include<stdio.h>
#include<stdlib.h>

typedef struct card {
    int num;
    struct card *next;
} Card;

Card *new_card(int num) {
    Card *res = malloc(sizeof(Card));
    res->num = num;
    res->next = NULL;
}

Card *build(int n) {
    Card *top, *p, *tmp;
    top = new_card(1);
    p = top;
    for (int i = 2;i <= n;i++) {
        p->next = new_card(i);
        p = p->next;
    }
    return top;
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    Card *deck_top, *deck_btm;
    deck_top = build(n);
    
    deck_btm = deck_top;
    while (deck_btm->next) deck_btm = deck_btm->next;

    int remain = n;
    while (m--) {
        // discard top
        printf("%d ", deck_top->num);
        Card *tmp = deck_top;
        deck_top = deck_top->next;
        free(tmp);
        remain--;

        if (remain == 0) break;
        if (remain == 1) continue;

        // move top card to bottom
        deck_btm->next = deck_top;
        deck_top = deck_top->next;
        deck_btm = deck_btm->next;
        deck_btm->next = NULL;
    }
    return 0;
}