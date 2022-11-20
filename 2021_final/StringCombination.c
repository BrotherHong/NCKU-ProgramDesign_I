#include<stdio.h>
#include<string.h>

int n, k;
char str[25][100];
char output[25][100];

// 已枚舉cnt項 正在選擇第cnt+1項 且這項在lst後
void solve(int cnt, int lst) {
    if (cnt == k) {
        int i;
        for (i = 0;i < k;i++) {
            printf("%s ", output[i]);
        }
        printf("\n");
        return;
    }
    int i;
    for (i = lst+1;i < n;i++) {
        strcpy(output[cnt], str[i]);
        solve(cnt+1, i);
    }
}

int main(void) {
    scanf("%d%d", &n, &k);
    int i;
    for (i = 0;i < n;i++) {
        scanf("%s", str[i]);
    }
    solve(0, -1);
    return 0;
}