#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int res[35];
    int idx = 0;
    while (n > 0) {
        res[idx++] = n%2;
        n /= 2;
    }
    for (int i = idx-1;i >= 0;i--) {
        printf("%d", res[i]);
    }
    return 0;
}