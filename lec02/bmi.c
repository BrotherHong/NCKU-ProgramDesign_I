#include<stdio.h>

int main(void) {
    int x, y;
    scanf("%d%d", &x, &y);
    float h = (float) x / 100.0;
    float w = (float) y;
    printf("%.6f", (float) w / (h * h));
    return 0;
}