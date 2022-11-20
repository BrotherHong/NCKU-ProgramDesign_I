#include<stdio.h>
#define MINE -100

int main(void) {
    int N, M;
    int g[10][10] = {0};
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            int t;
            scanf("%d", &t);
            if (t == 0) 
                continue;
            g[i][j] = MINE;
            for (int r = i-1;r <= i+1;r++) {
                for (int c = j-1;c <= j+1;c++) {
                    if (0 <= r && r < N && 0 <= c && c < M) {
                        g[r][c]++;
                    }
                }
            }
        }
    }
    const char numbers[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "boom"};
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            int num = g[i][j];
            num = (num >= 0 ? num : 9);
            if (j > 0) printf(" ");
            printf("|| :%s: ||", numbers[num]);
        }
        printf("\n");
    }
    return 0;
}