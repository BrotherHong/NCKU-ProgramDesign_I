#include<stdio.h>
#define NUM_PLAYER 4

typedef struct {
    int rank;
    char suit; // c(club) < d(diamond) < h(heart) < s(spades)
} Card;

typedef struct {
    char name;
    Card cards[5];
    enum cards_type {
        STRAIGHT_FLUSH = 1,
        FOUR_OF_A_KIND,
        FULL_HOUSE,
        FLUSH,
        STRAIGHT,
        THREE_OF_A_KIND,
        TWO_PAIRS,
        PAIR,
        HIGH_CARD,
    } type;
} PokerHand;

void sort_hand_cards(Card cards[]); // len == 5
void classify_hand_cards(PokerHand *hand);
void justify_hand_cards(PokerHand *hand);

// is function
int is_straight(const Card cards[]);
int is_flush(const Card cards[]);
int is_four_kind(const Card cards[]);
int is_full_house(const Card cards[]);
int is_three_kind(const Card cards[]);
int is_two_pair(const Card cards[]);
int is_pair(const Card cards[]);

// compare function
int cmp_card(const Card c1, const Card c2);
int cmp_hand_cards(const PokerHand h1, const PokerHand h2);

// other
void rotate_left_cards(Card cards[], int times);
void swap_card(Card *a, Card *b);

// for test
void print_poker_hand(PokerHand hand);

int main(void) {
    PokerHand players[NUM_PLAYER]; // A B C D
    // init
    for (int i = 0;i < NUM_PLAYER;i++) {
        players[i].name = i + 'A';
    }
    // input
    for (int i = 0;i < NUM_PLAYER;i++) {
        for (int j = 0;j < 5;j++) {
            char rk_c = getchar();
            char suit = getchar();
            getchar(); // read ' ' or '\n'

            int rk_i;
            switch (rk_c) {
                case 'a': rk_i = 14; break;
                case 't': rk_i = 10; break;
                case 'j': rk_i = 11; break;
                case 'q': rk_i = 12; break;
                case 'k': rk_i = 13; break;
                default: rk_i = rk_c - '0';
            }

            players[i].cards[j].rank = rk_i;;
            players[i].cards[j].suit = suit;
        }
    }

    for (int i = 0;i < NUM_PLAYER;i++) {
        sort_hand_cards(players[i].cards);
        classify_hand_cards(&players[i]);
        justify_hand_cards(&players[i]);
        // print_poker_hand(players[i]);
    }

    for (int i = NUM_PLAYER-1;i > 0;i--) {
        for (int j = 0;j < i;j++) {
            if (cmp_hand_cards(players[j], players[j+1]) < 0) {
                PokerHand tmp = players[j];
                players[j] = players[j+1];
                players[j+1] = tmp;
            }
        }
    }

    for (int i = 0;i < NUM_PLAYER;i++) {
        printf("%c ", players[i].name);
    }

    return 0;
}

// function definition
void sort_hand_cards(Card cards[]) {
    for (int i = 5-1;i > 0;i--) {
        for (int j = 0;j < i;j++) {
            if (cmp_card(cards[j], cards[j+1]) > 0) {
                Card tmp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = tmp;
            }
        }
    }
}

void classify_hand_cards(PokerHand *hand) {
    if (is_straight(hand->cards) && is_flush(hand->cards)) {
        hand->type = STRAIGHT_FLUSH;
    } else if (is_four_kind(hand->cards)) {
        hand->type = FOUR_OF_A_KIND;
    } else if (is_full_house(hand->cards)) {
        hand->type = FULL_HOUSE;
    } else if (is_flush(hand->cards)) {
        hand->type = FLUSH;
    } else if (is_straight(hand->cards)) {
        hand->type = STRAIGHT;
    } else if (is_three_kind(hand->cards)) {
        hand->type = THREE_OF_A_KIND;
    } else if (is_two_pair(hand->cards)) {
        hand->type = TWO_PAIRS;
    } else if (is_pair(hand->cards)) {
        hand->type = PAIR;
    } else {
        hand->type = HIGH_CARD;
    }
}

void justify_hand_cards(PokerHand *hand) {
    Card *c = hand->cards;
    enum cards_type type = hand->type;

    if (type == STRAIGHT_FLUSH || type == STRAIGHT ||
        type == FLUSH || type == HIGH_CARD) 
    return;

    int combi;
    if (type == FOUR_OF_A_KIND) {
        combi = is_four_kind(c);
        if (combi == 2) {
            rotate_left_cards(c, 1);
        }
    } else if (type == FULL_HOUSE) {
        combi = is_full_house(c);
        if (combi == 2) {
            rotate_left_cards(c, 2);
        }
    } else if (type == THREE_OF_A_KIND) {
        combi = is_three_kind(c);
        if (combi == 2) {
            rotate_left_cards(c, 1);
        } else if (combi == 3) {
            rotate_left_cards(c, 2);
        }
    } else if (type == TWO_PAIRS) {
        combi = is_two_pair(c);
        if (combi == 2) {
            rotate_left_cards(c, 1);
            swap_card(&c[0], &c[2]);
            swap_card(&c[1], &c[3]);
        } else if (combi == 3) {
            rotate_left_cards(c, 1);
        }
    } else if (type == PAIR) {
        combi = is_pair(c);
        if (combi == 2) {
            rotate_left_cards(c, 1);
        } else if (combi == 3) {
            rotate_left_cards(c, 2);
        } else if (combi == 4) {
            rotate_left_cards(c, 3);
        }
    }
}

// is function
int is_straight(const Card cards[]) {
    for (int i = 0;i < 5-1;i++) {
        if (cards[i].rank - cards[i+1].rank != -1) {
            return 0;
        }
    }
    return 1;
}

int is_flush(const Card cards[]) {
    for (int i = 0;i < 5-1;i++) {
        if (cards[i].suit != cards[i+1].suit) {
            return 0;
        }
    }
    return 1;
}

int is_four_kind(const Card cards[]) {
    if (cards[0].rank == cards[1].rank && 
        cards[1].rank == cards[2].rank &&
        cards[2].rank == cards[3].rank)
    return 1; // aaaab

    if (cards[1].rank == cards[2].rank && 
        cards[2].rank == cards[3].rank &&
        cards[3].rank == cards[4].rank)
    return 2; // baaaa

    return 0;
}

int is_full_house(const Card cards[]) {
    if (cards[0].rank == cards[1].rank && 
        cards[1].rank == cards[2].rank &&
        cards[3].rank == cards[4].rank)
    return 1; // aaabb

    if (cards[0].rank == cards[1].rank && 
        cards[2].rank == cards[3].rank &&
        cards[3].rank == cards[4].rank)
    return 2; // bbaaa

    return 0;
}

int is_three_kind(const Card cards[]) {
    if (cards[0].rank == cards[1].rank && 
        cards[1].rank == cards[2].rank)
    return 1; // aaabc

    if (cards[1].rank == cards[2].rank && 
        cards[2].rank == cards[3].rank)
    return 2; // baaac

    if (cards[2].rank == cards[3].rank && 
        cards[3].rank == cards[4].rank)
    return 3; // bcaaa

    return 0;
}

int is_two_pair(const Card cards[]) {
    if (cards[0].rank == cards[1].rank && 
        cards[2].rank == cards[3].rank)
    return 1; // aabbc

    if (cards[0].rank == cards[1].rank && 
        cards[3].rank == cards[4].rank)
    return 2; // aacbb

    if (cards[1].rank == cards[2].rank && 
        cards[3].rank == cards[4].rank)
    return 3; // caabb

    return 0;
}

int is_pair(const Card cards[]) {
    if (cards[0].rank == cards[1].rank)
    return 1; // aabcd

    if (cards[1].rank == cards[2].rank)
    return 2; // baacd

    if (cards[2].rank == cards[3].rank)
    return 3; // bcaad

    if (cards[3].rank == cards[4].rank)
    return 4; // bcdaa

    return 0;
}

// compare function
int cmp_card(const Card c1, const Card c2) {
    if (c1.rank == c2.rank) {
        return c1.suit > c2.suit ? -1 : 1; // s h d c
    }
    return c1.rank < c2.rank ? -1 : 1;
}

int cmp_hand_cards(const PokerHand h1, const PokerHand h2) {
    if (h1.type == h2.type) {
        enum cards_type type = h1.type;
        if (type == STRAIGHT_FLUSH ||
            type == FLUSH || 
            type == STRAIGHT ||
            type == HIGH_CARD) 
        {
            if (h1.cards[4].rank == h2.cards[4].rank) {
                return h1.cards[4].suit < h2.cards[4].suit ? -1 : 1;
            }
            return h1.cards[4].rank < h2.cards[4].rank ? -1 : 1;
        } 
        else if (type == FOUR_OF_A_KIND || 
                    type == FULL_HOUSE ||
                    type == THREE_OF_A_KIND) 
        {
            return h1.cards[0].rank < h2.cards[0].rank ? -1 : 1;
        }
        else if (type == TWO_PAIRS) {
            if (h1.cards[2].rank == h2.cards[2].rank) {
                return h1.cards[2].suit < h2.cards[2].suit ? -1 : 1;
            }
            return h1.cards[2].rank < h2.cards[2].rank ? -1 : 1;
        }
        else if (type == PAIR) {
            if (h1.cards[0].rank == h2.cards[0].rank) {
                return h1.cards[0].suit < h2.cards[0].suit ? -1 : 1;
            }
            return h1.cards[0].rank < h2.cards[0].rank ? -1 : 1;
        }
    }
    return h1.type > h2.type ? -1 : 1;
}

// other
void rotate_left_cards(Card cards[], int times) {
    Card tmp;
    while (times--) {
        for (int i = 0;i < 5-1;i++) {
            swap_card(&cards[i], &cards[i+1]);
        }
    }
}

void swap_card(Card *a, Card *b) {
    Card tmp = *a;
    *a = *b;
    *b = tmp;
}

// for test
void print_poker_hand(PokerHand hand) {
    for (int i = 0;i < 5;i++) {
        printf("(%d)%c ", hand.cards[i].rank, hand.cards[i].suit);
    }
    printf("TYPE: %d\n", hand.type);
}