#include<stdio.h>
#include<math.h>

int main(void) {
    int x;
    scanf("%d", &x);
    int x1 = (x > 5000 ? x : lround(x * 1.08));
    int x2 = (x > 5000 ? x : lround(x * 1.1));
    int y1 = lround(x1 * 0.2966);
    int y2 = lround(x2 * 0.2178);
    printf("%d", y1-y2);
    return 0;
}