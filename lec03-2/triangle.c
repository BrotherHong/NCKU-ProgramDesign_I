#include<stdio.h>

int main(void) {
    int a, b, i, j;
    scanf("%d%d", &a, &b);
    if (a == 1) {
        for (i = b; i >= 1; i--) {
            for (j = i; j >= 1; j--) {
                printf("*");
            }
            printf("\n");
        }
    } else if (a == 2) {
        for (i = 1; i <= b; i++) {
            for (j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else if (a == 3) {
        for (i = b; i >= 1; i--) {
            // space
            for (j = 1; j <= b-i; j++) {
                printf(" ");
            }
            // star
            for (j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else { // a == 4
        for (i = 1; i <= b; i++) {
            // space
            for (j = 1; j <= b-i; j++) {
                printf(" ");
            }
            // star
            for (j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}