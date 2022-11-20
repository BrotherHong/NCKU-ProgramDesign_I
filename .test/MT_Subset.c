#include<stdio.h>

int main(void) {
    int N;
    char sa[30];
    scanf("%d", &N);
    getchar(); // read '\n'
    for (int i = 0;i < N;i++) {
        sa[i] = getchar();
    }
    for (int b = 1;b < (1 << N);b++) {
        for (int j = 0;j < N;j++) {
            if (b & (1 << j)) {
                putchar(sa[j]);
            }
        }
        printf("\n");
    }
    return 0;
}