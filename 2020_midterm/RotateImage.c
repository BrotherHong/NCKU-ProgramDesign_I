#include<stdio.h>

int M, N;
int image[101][101];
int tmp[101][101];

void rotate90() {
    int newM = N;
    int newN = M;
    // copy image to tmp
    for (int i = 1;i <= M;i++) {
        for (int j = 1;j <= N;j++) {
            tmp[i][j] = image[i][j];
        }
    }
    // rotate
    for (int i = 1;i <= newM;i++) {
        for (int j = 1;j <= newN;j++) {
            image[i][j] = tmp[M-j+1][i];
        }
    }
    // update
    M = newM;
    N = newN;
}

int main(void) {
    int deg;
    scanf("%d", &deg);
    scanf("%d%d", &M, &N);
    // input
    for (int i = 1;i <= M;i++) {
        for (int j = 1;j <= N;j++) {
            scanf("%d", &image[i][j]);
        }
    }
    // rotate
    deg /= 90;
    while (deg--) {
        rotate90();
    }
    // print
    for (int i = 1;i <= M;i++) {
        for (int j = 1;j <= N;j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}