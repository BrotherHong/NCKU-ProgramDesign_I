#include<stdio.h>

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", gcd(a, b));
    }
    return 0;
}