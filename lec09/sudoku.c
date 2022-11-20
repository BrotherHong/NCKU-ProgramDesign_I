#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

//

void find_repeat(int arr[], int repeat[], int *repeat_N) {
    int cnt[10] = {0};
    for (int i = 0;i < NUM;i++) {
        cnt[arr[i]]++;
    }
    for (int i = 1;i <= NUM;i++) {
        if (cnt[i] > 1) {
            repeat[(*repeat_N)++] = i;
        }
    }
}

void check_sudoku(int (*grid_p)[NUM]){
    int ans[NUM][NUM] = {0};
    //
    // row
    for (int i = 0;i < NUM;i++) {
        int arr[NUM];
        for (int j = 0;j < NUM;j++) {
            arr[j] = grid_p[i][j];
        }
        int repeat[NUM];
        int repeat_N = 0;
        find_repeat(arr, repeat, &repeat_N);
        for (int r = 0;r < repeat_N;r++) {
            for (int j = 0;j < NUM;j++) {
                if (grid_p[i][j] == repeat[r]) {
                    ans[i][j] = 1;
                }
            }
        }
    }
    // column
    for (int j = 0;j < NUM;j++) {
        int arr[NUM];
        for (int i = 0;i < NUM;i++) {
            arr[i] = grid_p[i][j];
        }
        int repeat[NUM];
        int repeat_N = 0;
        find_repeat(arr, repeat, &repeat_N);
        for (int r = 0;r < repeat_N;r++) {
            for (int i = 0;i < NUM;i++) {
                if (grid_p[i][j] == repeat[r]) {
                    ans[i][j] = 1;
                }
            }
        }
    }
    // block
    for (int r = 0;r < 3;r++) {
        for (int c = 0;c < 3;c++) {
            int arr[NUM];
            int idx = 0;
            for (int i = r*3;i < r*3+3;i++) {
                for (int j = c*3;j < c*3+3;j++) {
                    arr[idx++] = grid_p[i][j];
                }
            }
            int repeat[NUM];
            int repeat_N = 0;
            find_repeat(arr, repeat, &repeat_N);
            for (int k = 0;k < repeat_N;k++) {
                for (int i = r*3;i < r*3+3;i++) {
                    for (int j = c*3;j < c*3+3;j++) {
                        if (grid_p[i][j] == repeat[k]) {
                            ans[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
    //
    for (int i = 0;i < NUM;i++) {
        for (int j = 0;j < NUM;j++) {
            if (ans[i][j]) {
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}