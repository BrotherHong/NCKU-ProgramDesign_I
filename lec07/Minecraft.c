#include<stdio.h>

int craft[21][21]; // craft[i][0] -> len

int needOriginal(int item) {
    int len = craft[item][0];
    if (len == 0) {
        return 1;
    }
    int result = 0;
    for (int j = 1;j <= len;j++) {
        result += needOriginal(craft[item][j]);
    }
    return result;
}

int main(void) {
    int N;
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) {
        int len;
        scanf("%d", &len);
        craft[i][0] = len;
        for (int j = 1;j <= len;j++) {
            scanf("%d", &craft[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1;i <= N;i++) {
        ans += needOriginal(i);
    }
    printf("%d", ans);
    return 0;
}