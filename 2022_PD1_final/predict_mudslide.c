#include<stdio.h>

int mp[5][5];
int dir[5] = {-1, 0, 1, 0, -1};
int ans = 0;

void solve(int r, int c) {

    for (int d = 0;d < 4;d++) {
        int rr = r+dir[d], cc = c+dir[d+1];
        if ((0 <= rr && rr < 5 && 0 <= cc && cc < 5) && mp[rr][cc] != 1) {
            if (mp[rr][cc] == 2) {
                ans++;
            }
            mp[rr][cc] = 1;
            solve(rr, cc);
        }
    }
}

int main(void) {
    int sr, sc;
    scanf("%d%d", &sr, &sc);
    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < 5;j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    //
    if (mp[sr][sc] == 2) {
        ans++;
    }
    mp[sr][sc] = 1;
    solve(sr, sc);
    printf("%d", ans);
    return 0;
}