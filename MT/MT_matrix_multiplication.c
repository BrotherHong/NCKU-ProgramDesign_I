#include<stdio.h>
#include<stdlib.h>

int **build_2d_array(int row, int col, int val) {
    int **result = malloc(sizeof(int*) * row);
    for (int i = 0;i < row;i++) {
        result[i] = malloc(sizeof(int) * col);
        for (int j = 0;j < col;j++) {
            result[i][j] = val;
        }
    }
    return result;
}

int main(void) {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    int **A = build_2d_array(n, m, 0);
    int **B = build_2d_array(m, p, 0);
    int **C = build_2d_array(n, p, 0);
    // input A
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            scanf("%d", &A[i][j]);
        }
    }
    // input B
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < p;j++) {
            scanf("%d", &B[i][j]);
        }
    }
    // calc C
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < p;j++) {
            for (int k = 0;k < m;k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // print result
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < p;j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}