#include<stdio.h>

int main(void) {
    int i;
    float x, h = 0, y;
    float w = 0.9f, u = 0.1f, b = -51.0f, u1 = -0.98f, b1 = 153.0f;
    scanf("%f", &x);
    for (i = 1;i <= 5;i++) {
        h = w*x + u*h + b;
        y = u1 * h + b1;
        printf("%.1f ", y);
        x = y;
    }
    return 0;
}