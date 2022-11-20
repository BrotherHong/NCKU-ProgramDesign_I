#include<stdio.h>

int N;
char instruction[11]; // instruction[round]
char shape[1025]; // shape[id]

int getRound(int range) {
    int round = 0;
    while (range > 1) {
        range >>= 1;
        round++;
    }
    return round;
}

int leftWin(char ls, char rs) {
    switch(ls) {
        case 'r':
            return rs == 's';
        case 'p':
            return rs == 'r';
        case 's':
            return rs == 'p';
    }
}

int winner(int lid, int rid) {
    if (lid == rid) {
        return lid;
    }
    int round = getRound(rid-lid+1);
    int mid = (lid+rid)/2;
    int lw = winner(lid, mid);
    int rw = winner(mid+1, rid);
    if (shape[lw] == shape[rw]) {
        if (instruction[round] == 'b') {
            return (lw > rw ? lw : rw);
        } else { // s
            return (lw < rw ? lw : rw);
        }
    } else {
        if (leftWin(shape[lw], shape[rw])) {
            return lw;
        } else {
            return rw;
        }
    }
    return -1;
}

int main(void) {
    scanf("%d", &N);
    getchar(); // raed '\n'
    for (int i = 1;i <= N;i++) {
        shape[i] = getchar();
    }
    getchar(); // read '\n'
    int totalRound = getRound(N);
    for (int i = 1;i <= totalRound;i++) {
        instruction[i] = getchar();
    }
    printf("%d", winner(1, N));
    return 0;
}