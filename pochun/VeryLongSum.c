#include<stdio.h>

int a[1000001], b[1000001];
int result[1000001];

int main(void) {
    int N;
    scanf("%d", &N);
    while (N-- > 0) {
        int M;
        scanf("%d", &M);
        for (int i = M;i >= 1;i--) {
            scanf("%d %d", &a[i], &b[i]);
        }
        int carry = 0;
        for (int i = 1;i <= M;i++) {
            result[i] = (a[i] + b[i] + carry) % 10;
            carry = (a[i] + b[i] + carry) / 10;
        }
        for (int i = M;i >= 1;i--) {
            printf("%d", result[i]);
        }
        printf("\n\n");
    }
    return 0;
}