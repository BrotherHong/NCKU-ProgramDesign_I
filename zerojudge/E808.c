#include<stdio.h>
#define MAX_N 25

int main(void) {
    int n;
    scanf("%d", &n);
    int cost[MAX_N] = {0};
    int h, m;
    scanf("%d%d", &h, &m);
    for (int i = 1;i <= n;i++) {
        int t;
        scanf("%d", &t);
        cost[i] = cost[i-1] + t;
    }
    while (1) {
        int q;
        scanf("%d", &q);
        if (q == 0) break;
        int minutes = h*60+m;
        minutes += cost[q];
        minutes %= 24*60;
        printf("%02d:%02d\n", minutes/60, minutes%60);
    }
    return 0;
}