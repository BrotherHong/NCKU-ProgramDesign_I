#include<stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))

int main(void) {
    int a, b;
    int n;
    scanf("%d%d", &a, &b);
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
        int t;
        int buyA = 0, buyB = 0;
        while (1) {
            scanf("%d", &t);
            if (t == 0) break;
            int abs = ABS(t);
            if (abs == a) {
                if (t > 0) {
                    buyA++;
                } else {
                    buyA--;
                }
            } else if (abs == b) {
                if (t > 0) {
                    buyB++;
                } else {
                    buyB--;
                }
            }
        }
        if (buyA > 0 && buyB > 0) {
            ans++;
        }   
    }
    printf("%d", ans);
    return 0;
}