#include<stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    int a1, b1, c1;
    int a2, b2, c2;
    int n;
    scanf("%d%d%d", &a1, &b1, &c1);
    scanf("%d%d%d", &a2, &b2, &c2);
    scanf("%d", &n);
    int mx = -1000000000;
    for (int i = 0;i <= n;i++) {
        int x1 = i, x2 = n-i;
        int y1 = a1*x1*x1 + b1*x1 + c1;
        int y2 = a2*x2*x2 + b2*x2 + c2;
        mx = MAX(mx, y1 + y2);
    }
    printf("%d\n", mx);
    return 0;
}