#include<stdio.h>
#include<math.h>
#define PI 3.14

int main(void) {
    int mode;
    scanf("%d", &mode);
    double len, l, w, h, r;
    switch (mode) {
        case 1:
            scanf("%lf", &len);
            printf("%.2f", len*len*len);
            break;
        case 2:
            scanf("%lf%lf%lf", &l, &w, &h);
            printf("%.2f", l*w*h);
            break;
        case 3:
            scanf("%lf%lf", &r, &h);
            printf("%.2f", PI*r*r*h);
            break;
        case 4:
            scanf("%lf", &len);
            printf("%.2f", sqrt(2)/12*len*len*len);
            break;
    }
    return 0;
}