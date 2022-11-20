#include<stdio.h>
#define MAX_N 101

int ref[MAX_N][MAX_N] = {0}; // ref[i][0] -> len

void solve(int id, int result[]) {
    if (ref[id][0] == 0) {
        result[id] = 1;
        return;
    }
    result[id] = 1;
    int len = ref[id][0];
    for (int i = 1;i <= len;i++) {
        solve(ref[id][i], result);
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    // input
    while (1) {
        int beRef;
        scanf("%d", &beRef);

        if (beRef == 0) {
            break;
        }

        int len = 0;
        while (1) {
            int ri;
            scanf("%d", &ri);
            ref[beRef][++len] = ri;
            char ch = getchar();
            if (ch == '\n') {
                ref[beRef][0] = len;
                break;
            }
        }
    }
    for (int i = 1;i <= N;i++) {
        int result[MAX_N] = {0};
        printf("%d -> ", i);
        solve(i, result);
        for (int j = 1;j <= N;j++) {
            if (result[j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}