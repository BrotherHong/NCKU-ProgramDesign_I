#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t * const queue, int value, int weight);
node_t *dequeue(prio_queue_t * const queue);
void print_nodes(const prio_queue_t * const queue);

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		}
		else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
        }
		print_nodes(&queue);
	}
	return 0;
}

void print_nodes(const prio_queue_t *const queue) {
	if (!queue->head) {
		printf("EMPTY\n");
		return;
	}
	for (node_t *node = queue->head; node; node = node->next) {
		printf(" -> %d", node->value);
    }
	printf("\n");
    return;
}

//

void enqueue(prio_queue_t *const queue, int value, int weight) {
    // create new node
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->weight = weight;

    node_t *cur = queue->head;
    node_t *prev = NULL;
    while (cur != NULL && cur->weight <= weight) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        new_node->next = cur;
        queue->head = new_node;
    } else if (cur == NULL) {
        prev->next = new_node;
    } else {
        new_node->next = cur;
        prev->next = new_node;
    }

}

node_t *dequeue(prio_queue_t *const queue) {
    if (queue->head == NULL) {
        return NULL;
    }
    node_t *result = queue->head;
    queue->head = queue->head->next;
    return result;
}