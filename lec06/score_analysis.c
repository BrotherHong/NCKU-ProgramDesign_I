#include<stdio.h>
#define MAX_N 1024

int main(void) {
    int N;
    int score[MAX_N];
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &score[i]);
    }
    int T, B, A;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &B, &A);
        int x, y, z;
        x = y = z = 0;
        for (int i = 0;i < N;i++) {
            if (score[i] < B) {
                x++;
            } else if (score[i] < A) {
                y++;
            } else {
                z++;
            }
        }
        printf("%d %d %d\n", x, y, z);
    }
    return 0;
}