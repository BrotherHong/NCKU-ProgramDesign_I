#include<stdio.h>
#define MAX_N 105

int ref[MAX_N][MAX_N] = {0};

int main(void) {
    int N;
    scanf("%d", &N);
    // input
    int r;
    while (1) {
        scanf("%d", &r);
        if (r == 0) break;
        int beRef;
        while (1) {
            scanf("%d", &beRef);
            char c = getchar();
            ref[r][beRef] = 1;
            if (c == '\n') {
                break;
            }
        }
    }
    // init
    for (int i = 1;i <= N;i++) {
        ref[i][i] = 1;
    }
    // main
    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= N;j++) {
            if (ref[i][j] == 1) {
                for (int k = 1;k <= N;k++) {
                    if (ref[j][k] == 1) {
                        ref[i][k] = 1;
                    }
                }
            }
        }
    }

    // output
    for (int i = 1;i <= N;i++) {
        printf("%d -> ", i);
        for (int j = 1;j <= N;j++) {
            if (ref[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}