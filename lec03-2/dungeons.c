#include<stdio.h>

int main(void) {
    int d1, d2, d3, d4, d5, d6;
    int player = 100, dragon = 100;
    int over = 0; // false
    while (!over) {
        scanf("%d%d%d%d%d%d", &d1, &d2, &d3, &d4, &d5, &d6);
        if ((d1+d2+d3)%2 == 1) {
            // player attack
            if (d4 < d5 && d5 < d6) {
                dragon -= 25;
            } else if (d4%2 == d5%2 || d5%2 == d6%2) {
                dragon -= 5;
            }
        } else {
            // dragon attack
            int d = d4 - d5;
            d = d < 0 ? -d : d;
            if (d > d6) {
                player -= 15;
            } else if (d4+d5 != d6) {
                player -= 5;
            }
        }
        if (player <= 0 || dragon <= 0) {
            over = 1; // true
        }
    }
    if (dragon > 0) {
        printf("Dragon wins");
    } else {
        printf("Player wins");
    }
    return 0;
}