#include<stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int main(void) {
    int i, j, price;
    scanf("%d%d", &i, &j);
    switch (i) {
        case 1:
            price = AMERICANO;
            break;
        case 2:
            price = LATTE;
            break;
        case 3:
            price = CAPPUCCINO;
            break;
        case 4:
            price = MOCHA;
            break;
        default:
            price = -1;
    }
    if (price == -1) {
        printf("Wait, what?");
    } else {
        printf("The total price is %d dollars!", price * j);
    }
    return 0;
}