#include<stdio.h>

int main(void) {
    int d1, d2, d3, d4, d5, d6;
    scanf("%d%d%d%d%d%d", &d1, &d2, &d3, &d4, &d5, &d6);
    if ((d1+d2+d3) <= 10) { // player attack
        printf("Player attacks: ");
        if ((d4 == d5) && (d5 == d6)) {
            printf("Critical Hit");
        } else if ((d4+d5) >= d6) {
            printf("Normal Hit");
        } else {
            printf("Miss");
        }
    } else { // dragon attack
        printf("Dragon attacks: ");
        if ((d4 == d5) || (d5 == d6) || (d4 == d6)) {
            printf("Miss");
        } else if ((d4+d5) != d6) {
            printf("Normal Hit");
        } else {
            printf("Critical Hit");
        }
    }
    return 0;
}