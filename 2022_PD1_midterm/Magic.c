#include<stdio.h>
#include<ctype.h>

int level[62] = {0};
int needBasic[62] = {0};
char subMagic[62][62]; // subMagic[i][0] -> length

// 0~9: 0~9 / a~z: 10~35 / A~Z: 36 ~ 61
int getIndex(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (islower(c)) {
        return c - 'a' + 10;
    } else {
        return c - 'A' + 36;
    }
    return -1; // never reached
}

void solve(char magic, int *lv, int *basic) {
    int id = getIndex(magic);

    // calculated
    if (level[id] != 0) {
        *lv = level[id];
        *basic = needBasic[id];
        return;
    }

    int len = (int)subMagic[id][0];
    // terminal
    // if (len == 0) {
    //     *lv = 1;
    //     *basic = 1;
    //     return;
    // }

    // recursion
    int mxLv = 0, tBasic = 0;
    for (int i = 1;i <= len;i++) {
        int l, b;
        solve(subMagic[id][i], &l, &b);
        tBasic += b;
        mxLv = (l > mxLv ? l : mxLv);
    }

    // record
    needBasic[id] = tBasic;
    level[id] = mxLv + 1;

    *basic = needBasic[id];
    *lv = level[id];
}

int main(void) {
    int N;
    scanf("%d", &N);
    getchar(); // read '\n'

    // init
    for (char c = 'a';c <= 'e';c++) {
        int idx = getIndex(c);
        level[idx] = 1;
        needBasic[idx] = 1;
    }

    // input
    for (int i = 1;i <= N;i++) {
        char root = getchar();
        int len = 0;
        getchar(); // (
        char ch;
        while ((ch = getchar()) != ')') {
            len = len*10 + (ch-'0');
        }
        for (int j = 1;j <= len;j++) {
            char c = getchar();
            subMagic[getIndex(root)][j] = c;
        }
        subMagic[getIndex(root)][0] = len;
        getchar(); // read '\n'
    }

    // solve
    int len = 0;
    getchar(); // (
    char ch;
    while ((ch = getchar()) != ')') {
        len = len*10 + (ch-'0');
    }
    int mxLv = 0, totalBasic = 0;
    for (int i = 1;i <= len;i++) {
        int basic, lv;
        solve(getchar(), &lv, &basic);
        totalBasic += basic;
        mxLv = (lv > mxLv ? lv : mxLv);
    }
    getchar(); // read '\n'
    printf("%d %d", mxLv+1, totalBasic);
    return 0;
}