#include<stdio.h>

int main(void) {
    int a, mx = -1, mn = 2147483647;
    while (scanf("%d", &a)) {
        if (a == -1) break;
        if (a > mx) mx = a;
        if (a < mn) mn = a;
    }
    printf("%d", mx - mn);
    return 0;
}