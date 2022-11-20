#include<stdio.h>

int main(void) {
    long long n;
    int a = 0, b = 0;
    scanf("%lld", &n);
    int i;
    for (i = 12;i >= 1;i--) {
        if (i%2 == 0) {
            a += n%10;
        } else {
            b += n%10;
        }
        n /= 10;
    }
    int x = a*3 + b;
    int y = x - 1;
    int z = y % 10;
    z = 9 - z;
    printf("%d", z);
    return 0;
}