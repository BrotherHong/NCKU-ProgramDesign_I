#include<stdio.h>

int main(void) {

    int w, h;
    scanf("%d %d", &w, &h);

    int pfl = 1; // position from left
    int pfr = h; // position from right

    for (int i = 1; i <= h; i++) { // 直
        for (int j = 1; j <= h; j++) { // 橫
            if ((pfl-(w-1) <= j && j <= pfl+(w-1)) || (pfr-(w-1) <= j && j <= pfr+(w-1))) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        pfl++;
        pfr--;
        printf("\n");
    }
    return 0;
}