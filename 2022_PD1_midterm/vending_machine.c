#include<stdio.h>

int store[4][11];

int main(void) {
    // init
    for (int i = 1;i <= 3;i++) {
        for (int j = 1;j <= 10;j++) {
            store[i][j] = 10;
        }
    }
    //
    int n;
    scanf("%d", &n);
    int total = 0;
    while (n--) {
        int tag, amount;
        scanf("%d%d", &tag, &amount);
        int r = ((tag-1)/10 + 1);
        int c = (tag%10 == 0 ? 10 : tag%10);
        if (amount > store[r][c]) {
            amount = store[r][c];
        }
        total += amount * (r * 10);
        store[r][c] -= amount;
    }
    for (int i = 1;i <= 3;i++) {
        for (int j = 1;j <= 10;j++) {
            printf("%d ", store[i][j]);
        }
        printf("\n");
    }
    printf("Earned: $%d", total);
    return 0;
}