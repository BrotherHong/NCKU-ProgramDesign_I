#include<iostream>
#include<queue>
#include<cstring>
#define MAX_N 305
using namespace std;
typedef pair<int, int> pr;

int N;
int g[MAX_N][MAX_N];
int steps[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int dir[5] = {0, 1, 0, -1, 0};

bool inBound(int r, int c) {
    return (1 <= r && r <= N && 1 <= c && c <= N);
}

int dHeight(int a, int b) {
    return abs(a-b);
}

int bfs(int mxH) {
    memset(vis, false, sizeof(vis));
    memset(steps, 0, sizeof(steps));

    bool finish = false;
    steps[N][N] = -1;

    queue<pr> q;
    vis[1][1] = true;
    q.push(make_pair(1, 1));

    while (!q.empty()) {
        pr p = q.front();
        q.pop();

        int r = p.first, c = p.second;

        for (int d = 0;d < 4;d++) {
            int rr = r+dir[d], cc = c+dir[d+1];
            if (inBound(rr, cc) && !vis[rr][cc] && dHeight(g[r][c], g[rr][cc]) <= mxH) {
                vis[rr][cc] = true;
                steps[rr][cc] = steps[r][c] + 1;
                q.push(make_pair(rr, cc));
            }
        }
    }

    return steps[N][N];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= N;j++) {
            cin >> g[i][j];
        }
    }
    int l = 0, r = 1000000, m;
    while (l < r) {
        m = (l+r) / 2;
        if (bfs(m) != -1) {
            r = m;
        } else {
            l = m+1;
        }
    }
    cout << l << '\n';
    cout << bfs(l) << '\n';
    return 0;
}