#include<stdio.h>

int main(void) {
    int d1, d2;
    int pass[7] = {0};
    for (int i = 1;i <= 75;i++) {
        scanf("%d%d", &d1, &d2);
        if (d2%2 == 0) { // even -> decrease
            pass[d1] = (pass[d1] - 1 + 10) % 10;
        } else { // odd -> increase
            pass[d1] = (pass[d1] + 1) % 10;
        }
    }
    for (int i = 1;i <= 6;i++) {
        printf("%d ", pass[i]);
    }
    return 0;
}