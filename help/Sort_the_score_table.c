#include<stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int N;
    int id[101], grade[101];
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) {
        scanf("%d%d", &id[i], &grade[i]);
    }
    // bubble sort
    for (int i = N;i > 1;i--) {
        for (int j = 1;j < i;j++) {
            int need_swap = 0;
            if (grade[j] == grade[j+1]) {
                if (id[j] > id[j+1]) {
                    need_swap = 1;
                }
            } else if (grade[j] < grade[j+1]) {
                need_swap = 1;
            }
            if (need_swap) {
                swap(&id[j], &id[j+1]);
                swap(&grade[j], &grade[j+1]);
            }
        }
    }
    for (int i = 1;i <= N;i++) {
        printf("%d %d\n", id[i], grade[i]);
    }
    return 0;
}