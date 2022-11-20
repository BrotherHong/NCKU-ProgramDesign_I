#include<stdio.h>

int N;
int magic[50][50] = {0}; // 0-indexed

int fix(int i) {
    if (i >= N) {
        return i % N;
    } else if (i < 0) {
        return i + N;
    }
    return i;
}

int main(void) {
    scanf("%d", &N);
    int i = 0, j = N/2;
    magic[i][j] = 1;
    for (int num = 2;num <= N*N;num++) {
        // move to next pos
        if (magic[fix(i-1)][fix(j+1)] == 0) {
            i = fix(i-1);
            j = fix(j+1);
        } else {
            i = fix(i+1);
            // j = j;
        }
        // assign
        magic[i][j] = num;
    }
    // print
    for (int x = 0;x < N;x++) {
        for (int y = 0;y < N;y++) {
            printf("%d ", magic[x][y]);
        }
        printf("\n");
    }
    return 0;
}