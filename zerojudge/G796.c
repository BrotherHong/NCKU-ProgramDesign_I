#include<stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int cnt[1000] = {0};
    while (N--) {
        int s;
        scanf("%d", &s);
        s = (s%1000) / 10;
        cnt[s]++;
    }
    for (int i = 0;i <= 999;i++) {
        if (cnt[i] > 0) {
            printf("%d %d\n", i, cnt[i]);
        }
    }
    return 0;
}