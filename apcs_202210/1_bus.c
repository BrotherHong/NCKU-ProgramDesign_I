#include<stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

int main(void) {
    int N;
    scanf("%d", &N);
    int x1, y1, x2, y2;
    scanf("%d%d", &x1, &y1);

    int mn = 10000;
    int mx = -1;
    for (int i = 1;i <= N-1;i++) {
        scanf("%d%d", &x2, &y2);
        mx = MAX(mx, ABS(x1-x2) + ABS(y1-y2));
        mn = MIN(mn, ABS(x1-x2) + ABS(y1-y2));
        x1 = x2;
        y1 = y2;
    }
    printf("%d %d\n", mx, mn);
    return 0;
}