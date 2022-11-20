#include<stdio.h>
#define SQRT3 1.7320508f

int main(void) {
    float a;
    scanf("%f", &a);
    printf("%.3f", SQRT3*a*a/4.0);
    return 0;
}