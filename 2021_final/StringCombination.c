#include<stdio.h>

int n, k;
char str[20][15];
int prt[20];

void solve(int last, int chs) {
    if (chs == k) {
        for (int i = 0;i < chs;i++) {
            printf("%s ", str[prt[i]]);
        }
        printf("\n");
        return;
    }
    for (int i = last+1;i < n;i++) {
        prt[chs] = i;
        solve(i, chs+1);
    }
}

int main(void) {
    scanf("%d%d", &n, &k);
    for (int i = 0;i < n;i++) {
        scanf("%s", str[i]);
    }
    solve(-1, 0);
    return 0;
}