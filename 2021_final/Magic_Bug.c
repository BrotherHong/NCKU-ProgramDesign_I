#include<stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    while (N--) {
        int stb;
        long long int num;
        scanf("%d-%llx", &stb, &num);
        int prt = 0;
        for (int i = 63;i >= 0;i--) {
            if (stb <= i && i <= stb+7) {
                printf("%d", (num & (1LL << i)) ? 1 : 0);
            } else {
                printf("0");
            }
            if (i != 0 && i%8 == 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}