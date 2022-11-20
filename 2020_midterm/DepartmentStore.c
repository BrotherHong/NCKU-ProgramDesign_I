#include<stdio.h>

int person[10001] = {0};

int main(void) {
    int m, n;
    scanf("%d%d", &m, &n);
    int p;
    while (m--) {
        scanf("%d", &p);
        person[p] = 1;
    }
    while (n--) {
        scanf("%d", &p);
        person[p] = 1;
    }
    for (int i = 1;i <= 10000;i++) {
        if (person[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}