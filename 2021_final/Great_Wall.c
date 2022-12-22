#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDER_ID_LEN 8
#define MAX_VILLAGE_NAME_LEN 15

typedef struct order_s {
	struct order_s *next;
	char order_id[ORDER_ID_LEN + 1];
	char consumer[MAX_VILLAGE_NAME_LEN + 1];
	enum {
		INGRED_A = 1,
		INGRED_B,
		INGRED_C,
	} ingredient_id;
	union {
		char ing_a[8];
		long ing_b;
		double ing_c;
	} amount;
} order_t;

typedef struct village_s {
	char name[MAX_VILLAGE_NAME_LEN + 1];
	unsigned long total_cost;
	order_t *order_list;
} village_t;

static const long unit_costs[] = {
	[INGRED_A] = 256,
	[INGRED_B] = 512,
	[INGRED_C] = 1024,
};

static village_t *init_village_array(int v_cnt);
static order_t *init_order_list(int o_cnt);
static void unify_orders(village_t *vills, int v_cnt, order_t *orders);
static void print_result(village_t *vills, int v_cnt);

int main()
{
	int village_cnt, order_cnt;
	scanf("%d%d", &village_cnt, &order_cnt);
	village_t *villages = init_village_array(village_cnt);
	if (!villages) {
		goto init_village_failed;
    }
	order_t *orders = init_order_list(order_cnt);
	if (!orders)  {
		goto init_order_failed;
    }
	unify_orders(villages, village_cnt, orders);
	print_result(villages, village_cnt);
	free(orders);

init_order_failed:
	free(villages);

init_village_failed:
	return 0;
}

static village_t *init_village_array(int v_cnt)
{
	village_t *villages = malloc(sizeof(village_t) * v_cnt);
	if (!villages) { // Ran out of memory
		return NULL;
    }
	for (int i = 0; i < v_cnt; i++) {
		scanf("%s", villages[i].name);
    }
	return villages;
}

static order_t *init_order_list(int o_cnt)
{
	order_t *orders = malloc(sizeof(order_t) * o_cnt);
	if (!orders) { // Ran out of memory
		return NULL;
    }
	for (int i = 0; i < o_cnt; i++) {
		// Read the content of order
		// the term %[^c] will use 'c' as delimiter while scanning the input
		scanf(" %[^:]:%u/%[^-]-%s",
				orders[i].order_id,
				&orders[i].ingredient_id,
				orders[i].amount.ing_a,
				orders[i].consumer);
		
		switch (orders[i].ingredient_id) {
			case INGRED_B:
				orders[i].amount.ing_b = atol(orders[i].amount.ing_a);
				break;
			case INGRED_C:
				orders[i].amount.ing_c = atof(orders[i].amount.ing_a);
				break;
			default:
				break;
		}
		// Construct orders into linked-list
		if (i) {
			orders[i - 1].next = orders + i;
        }
	}
	// End the linked-list
	orders[o_cnt - 1].next = NULL;
	return orders;
}

static void print_result(village_t *vills, int v_cnt)
{
	for (int i = 0; i < v_cnt; i++) {
		printf("%s %ld\n  ->", vills[i].name, vills[i].total_cost);
		for (order_t *optr = vills[i].order_list; optr; optr = optr->next) {
			printf(" %s", optr->order_id);
        }
		printf("\n");
	}
}

//

int find_village_id(village_t *vills, int v_cnt, const char *name) {
    for (int i = 0;i < v_cnt;i++) {
        if (strcmp(vills[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int hexCmp(const char *a, const char *b) {
	for (int i = 0;i < 8;i++) {
		int na = (a[i] > '9' ? a[i]-'A'+10 : a[i]-'0');
		int nb = (b[i] > '9' ? b[i]-'A'+10 : b[i]-'0');
		if (na > nb) return 1;
		else if (na < nb) return -1;
	}
	return 0;
}

// sort by order id
void push_order(order_t **head, order_t *order) {
    order_t *cpy = malloc(sizeof(order_t));
	*cpy = *order;
	cpy->next = NULL;

	if (*head == NULL) {
		*head = cpy;
		return;
	}
	order_t *cur = *head;
	order_t *prev = NULL;

	while (cur && hexCmp(cur->order_id, cpy->order_id) < 0) {
		prev = cur;
		cur = cur->next;
	}

	if (prev == NULL) {
		cpy->next = cur;
		*head = cpy;
	} else if (cur == NULL) {
		prev->next = cpy;
	} else {
		prev->next = cpy;
		cpy->next = cur;
	}
}

unsigned long get_ingr_cost(order_t *order) {
	unsigned long amt;
	switch (order->ingredient_id) {
		case INGRED_A:
			amt = atol(order->amount.ing_a);
			return amt * unit_costs[INGRED_A];
		case INGRED_B:
			amt = order->amount.ing_b;
			return amt * unit_costs[INGRED_B];
		case INGRED_C:
			amt = (unsigned long) order->amount.ing_c;
			return amt * unit_costs[INGRED_C];
	}
}

static void unify_orders(village_t *vills, int v_cnt, order_t *orders) {
    // init
    for (int i = 0;i < v_cnt;i++) {
        vills[i].order_list = NULL;
        vills[i].total_cost = 0;
    }
    //
    order_t *p = orders;
    for (; p; p = p->next) {
        int vill_id = find_village_id(vills, v_cnt, p->consumer);
        if (vill_id == -1) {
            printf("ERROR");
            return;
        }
        push_order(&vills[vill_id].order_list, p);
        vills[vill_id].total_cost += get_ingr_cost(p);
    }
    // sort vills by name
    for (int i = v_cnt-1;i > 0;i--) {
        for (int j = 0;j < i;j++) {
            if (strcmp(vills[j].name, vills[j+1].name) > 0) {
                village_t tmp = vills[j];
                vills[j] = vills[j+1];
                vills[j+1] = tmp;
            }
        }
    }
}
