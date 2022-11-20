#include<stdio.h>

int main(void) {
    double R;
    int N;
    scanf("%lf%d", &R, &N);
    double result = 1;
    while (N--) {
        result *= R;
    }
    printf("%d", (int)result);
    return 0;
}