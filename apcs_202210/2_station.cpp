#include<iostream>
using namespace std;

/**********************************
*   A    B     C     D      E
*   @  # # @  # @      @     @
*   #         # #  # # #   # #
*   #                      # #
*   #
***********************************/

int R, C;
bool g[35][55] = {false}; // 0 0

bool checkAvl(char type, int x, int y) {
    switch (type) {
        case 'A':
            if (x+3 >= R)
                return false;
            return !(g[x][y] | g[x+1][y] | g[x+2][y] | g[x+3][y]);
        case 'B':
            if (y-2 < 0)
                return false;
            return !(g[x][y-2] | g[x][y-1] | g[x][y]);
        case 'C':
            if (x+1 >= R || y-1 < 0)
                return false;
            return !(g[x][y] | g[x][y-1] | g[x+1][y-1] | g[x+1][y]);
        case 'D':
            if (y-2 < 0 || x+1 >= R)
                return false;
            return !(g[x][y] | g[x+1][y-2] | g[x+1][y-1] | g[x+1][y]);
        case 'E':
            if (y-1 < 0 || x+2 >= R) 
                return false;
            return !(g[x][y] | g[x+1][y-1] | g[x+1][y] | g[x+2][y-1] | g[x+2][y]);
    }
    return false;
}

void setGraph(char type, int x, int y) {
    switch (type) {
        case 'A':
            g[x][y] = g[x+1][y] = g[x+2][y] = g[x+3][y] = true;
            break;
        case 'B':
            g[x][y-2] = g[x][y-1] = g[x][y] = true;
            break;
        case 'C':
            g[x][y-1] = g[x][y] = true;
            g[x+1][y-1] = g[x+1][y] = true;
            break;
        case 'D':
            g[x][y] = true;
            g[x+1][y-2] = g[x+1][y-1] = g[x+1][y] = true;
            break;
        case 'E':
            g[x][y] = true;
            g[x+1][y-1] = g[x+1][y] = true;
            g[x+2][y-1] = g[x+2][y] = true;
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> R >> C >> n;

    int space = 0, discard = 0;

    char type;
    int h;
    while (n--) {
        cin >> type >> h;
        int i;
        bool placable = false;
        for (i = C-1;i >= 0;i--) {
            if (!checkAvl(type, h, i)) {
                break;
            } else if (!placable) {
                placable = true;
            }
        }
        if (placable) {
            setGraph(type, h, i+1);
        } else {
            discard++;
        }
    }

    // space
    for (int i = 0;i < R;i++) {
        for (int j = 0;j < C;j++) {
            if (g[i][j] == false) {
                space++;
            }
        }
    }

    cout << space << " " << discard << '\n';
    return 0;
}