#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MARKET_SIZE 50

typedef enum
{
    BUY,
    SELL
} action_type;

typedef struct _order
{
    char stock_id[5];
    action_type action;
    float price;
    int amount;
    struct _order *next;
} order;

typedef struct
{
    char stock_id[5];
    int trading_volumn;
    float opening_price;
    float closing_price;
    float highest_price;
    float lowest_price;
    order *buy_orders;
    order *sell_orders;
} subject;

subject market[MARKET_SIZE];

void make_order(order *new_order);

int cmp(const void *a, const void *b)
{
    subject *subjectA = (subject *)a;
    subject *subjectB = (subject *)b;

    return (subjectB->trading_volumn - subjectA->trading_volumn);
}

void print_price(float price){
    if(price < 50) printf("  %6.2f", price);
    else if(price < 500) printf("  %6.1f", price);
    else printf("  %6.0f", price);
}

int main()
{
    char buffer[30], target[5], action[5];
    float price;
    int amount;

    while (fgets(buffer, 30, stdin) != NULL)
    {
        if(buffer[0] == '\n') break;
        sscanf(buffer, "%s %s %f %d\n", target, action, &price, &amount);

        order *new_order = (order *)malloc(sizeof(order));

        strcpy(new_order->stock_id, target);
        new_order->action = strcmp(action, "BUY") ? SELL : BUY;
        new_order->price = price;
        new_order->amount = amount;
        new_order->next = NULL;

        make_order(new_order);
    }

    qsort(market, MARKET_SIZE, sizeof(subject), cmp);

    printf("stock_id  volumn    open   close    high     low\n");
    for (int i = 0; i < MARKET_SIZE && market[i].stock_id[0] != '\0'; ++i)
    {
        printf("%s      %6d", market[i].stock_id ,market[i].trading_volumn);
        print_price(market[i].opening_price);
        print_price(market[i].closing_price);
        print_price(market[i].highest_price);
        print_price(market[i].lowest_price);
        printf("\n");
    }

    return 0;
}

// upload code
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int len_market = 0;
subject *get_market(const char *id);
void *update_market(subject *mk, float price);

void push_buy_order(subject *mk, order *b);
void push_sell_order(subject *mk, order *s);

void pop_top_buy_order(subject *mk); // only pop 1 order
void pop_low_sell_order(subject *mk);

void make_order(order *new_order){
    subject *mk = get_market(new_order->stock_id);

    if (new_order->action == BUY) {
        while (new_order->amount > 0) {
            float low_sell = (mk->sell_orders ? mk->sell_orders->price : -1);

            if (low_sell == -1 || new_order->price < low_sell) {
                push_buy_order(mk, new_order);
                break;

            } else { // price >= low_sell
                float deal_price = low_sell;
                update_market(mk, deal_price);
                pop_low_sell_order(mk);
                new_order->amount--;
            }
        }
    } else { // SELL
        while (new_order->amount > 0) {
            float top_buy = (mk->buy_orders ? mk->buy_orders->price : -1);

            if (top_buy == -1 || new_order->price > top_buy) {
                push_sell_order(mk, new_order);
                break;

            } else { // price <= top_buy
                float deal_price = top_buy;
                update_market(mk, deal_price);
                pop_top_buy_order(mk);
                new_order->amount--;
            }
        }
    }
    for (int i = len_market;i < MARKET_SIZE;i++) {
        market[i].stock_id[0] = '\0';
    }
}

subject *get_market(const char *id) {
    for (int i = 0;i < len_market;i++) {
        if (strcmp(market[i].stock_id, id) == 0) {
            return &market[i];
        }
    }
    // if not found
    subject *nw = &market[len_market++];
    strcpy(nw->stock_id, id);
    nw->buy_orders = NULL;
    nw->sell_orders = NULL;
    nw->closing_price = 0;
    nw->opening_price = 0;
    nw->highest_price = 0;
    nw->lowest_price = 1e9;
    nw->trading_volumn = 0;

    return nw;
}

void *update_market(subject *mk, float price) {
    mk->trading_volumn++;

    if (mk->opening_price == 0) {
        mk->opening_price = price;
    }

    mk->closing_price = price;
    
    mk->highest_price = MAX(mk->highest_price, price);

    mk->lowest_price = MIN(mk->lowest_price, price);
}

void push_buy_order(subject *mk, order *b) { // large -> small

    if (mk->buy_orders == NULL) {
        mk->buy_orders = b;
        return;
    }

    order *cur = mk->buy_orders;
    order *prev = NULL;
    while (cur != NULL && cur->price >= b->price) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        b->next = mk->buy_orders;
        mk->buy_orders = b;
        return;
    }

    if (cur == NULL) {
        prev->next = b;
        return;
    }

    prev->next = b;
    b->next = cur;
}

void push_sell_order(subject *mk, order *s) { // small -> large

    if (mk->sell_orders == NULL) {
        mk->sell_orders = s;
        return;
    }

    order *cur = mk->sell_orders;
    order *prev = NULL;
    while (cur != NULL && cur->price <= s->price) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        s->next = mk->sell_orders;
        mk->sell_orders = s;
        return;
    }

    if (cur == NULL) {
        prev->next = s;
        return;
    }

    prev->next = s;
    s->next = cur;
}

void pop_top_buy_order(subject *mk) { // only pop 1 order

    if (--(mk->buy_orders->amount) == 0) {
        order *tmp = mk->buy_orders;
        mk->buy_orders = mk->buy_orders->next;
        free(tmp);
    }
} 

void pop_low_sell_order(subject *mk) {
    if (--(mk->sell_orders->amount) == 0) {
        order *tmp = mk->sell_orders;
        mk->sell_orders = mk->sell_orders->next;
        free(tmp);
    }
}