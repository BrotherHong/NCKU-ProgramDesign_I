#include<stdio.h>
#define SIZE 8

int table[SIZE][SIZE];
int record[SIZE][SIZE] = {0};

void setRecord(int num) {
    for (int i = 0;i < SIZE;i++) {
        for (int j = 0;j < SIZE;j++) {
            if (table[i][j] == num) {
                record[i][j] = 1;
                return;
            }
        }
    }
}

int main(void) {
    // Input
    for (int i = 0;i < SIZE;i++) {
        for (int j = 0;j < SIZE;j++) {
            scanf("%d", &table[i][j]);
        }
    }
    int num;
    for (int i = 0;i < 64;i++) {
        scanf("%d", &num);
        setRecord(num);
    }
    int lines = 0;
    
    //
    for (int r = 0;r < SIZE;r++) {
        int cnt = 0;
        for (int c = 0;c < SIZE;c++) {
            if (record[r][c]) {
                cnt++;
            }
        }
        if (cnt == SIZE) {
            lines++;
        }
    }

    //
    for (int c = 0;c < SIZE;c++) {
        int cnt = 0;
        for (int r = 0;r < SIZE;r++) {
            if (record[r][c]) {
                cnt++;
            }
        }
        if (cnt == SIZE) {
            lines++;
        }
    }

    //
    int cnt = 0;
    for (int r = 0, c = 0;r < SIZE;r++, c++) {
        if (record[r][c]) {
            cnt++;
        }
    }
    if (cnt == SIZE)
        lines++;
    
    //
    cnt = 0;
    for (int r = 0, c = SIZE-1;r < SIZE;r++, c--) {
        if (record[r][c]) {
            cnt++;
        }
    }
    if (cnt == SIZE)
        lines++;

    // output
    printf("%d", lines);
    return 0;
}