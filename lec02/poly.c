#include<stdio.h>
#include<math.h>

// 7x^4 - 8x^3 - x^2 + 6x - 22

int main(void) {
    float x;
    scanf("%f", &x);
    printf("%.1f", 7.0*powf(x, 4) - 8.0*powf(x, 3) - powf(x, 2) + 6.0*x - 22.0);
    return 0;
}