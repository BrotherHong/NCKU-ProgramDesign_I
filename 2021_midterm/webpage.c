#include<stdio.h>
#define MAX_N 105
#define ERROR 0.0000001

int link[MAX_N][MAX_N]; // link[i][0] -> length, start at index 1
double rank[MAX_N];

int main(void) {
    int N;
    scanf("%d", &N);
    // init
    for (int i = 0;i < N;i++) {
        rank[i] = 1.0 / N;
    }
    // input
    for (int i = 0;i < N;i++) {
        int len = 0, tmp;
        while (1) {
            scanf("%d", &tmp);
            if (tmp == -1) {
                link[i][0] = len;
                break;
            }
            link[i][++len] = tmp;
        }
    }
    
    while (1) {
        double delta[MAX_N] = {0.0};
        for (int i = 0;i < N;i++) {
            int len = link[i][0];
            for (int j = 1;j <= len;j++) {
                int target = link[i][j];
                delta[target] += rank[i] / len;
            }
        }
        // check break
        int out = 1;
        for (int i = 0;i < N;i++) {
            double d = rank[i] - delta[i];
            d = (d > 0 ? d : -d);
            if (d > ERROR) {
                out = 0;
                break;
            }
        }
        if (out) break;
        // prepare to next round
        for (int i = 0;i < N;i++) {
            rank[i] = delta[i];
        }
    }
    for (int i = 0;i < N;i++) {
        printf("%.2f%% ", rank[i]*100);
    }
    return 0;
}