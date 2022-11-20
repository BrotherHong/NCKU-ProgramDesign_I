#include<stdio.h>

int main(void) {
    double ans = 1.0;
    for (int i=1;i <= 5;i++) {
        double p;
        scanf("%lf", &p);
        ans *= p;
    }
    printf("%.15f", ans);
    return 0;
}