#include<stdio.h>
#define MAX 1440

int main(void) {
    int h, m, t;
    int n;

    scanf("%d:%d", &h, &m);
    scanf("%d", &n);
    t = h*60 + m;

    int x, H, M, T, cost;
    int ans = -1, mn = MAX*2 + 1;
    while (n--) {
        scanf("%d %d:%d %d", &x, &H, &M, &cost);
        T = H*60 + M;
        if (T < t) continue;
        if (T+cost < mn) {
            mn = T+cost;
            ans = x;
        }
    }
    printf("%d", ans);
    return 0;
}