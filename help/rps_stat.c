#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define GAMES_NUM 1000000

// r: rock / p: paper / s: scissor
char getShape() {
    const char shape[] = "rps";
    return shape[rand()%3];
}

// return -1 if a win, 0 if tie, 1 if b win
int winner(char a, char b) {
    if (a == b) return 0;
    switch (a) {
        case 'r':
            if (b == 'p') return 1;
            else return -1;
        case 'p':
            if (b == 's') return 1;
            else return -1;
        case 's':
            if (b == 'r') return 1;
            else return -1;
    }
}

int win_cnt[GAMES_NUM+1][2] = {0}; // 0: you, 1: enemy
int over[GAMES_NUM+1] = {0};

int main(void) {
    // setting random seed
    srand(time(NULL));
    int round = 0;
    int total_over = 0;
    int total_win = 0;
    int total_len = 0;
    while (total_over < GAMES_NUM) {
        round++;
        int won = 0, lost = 0;
        for (int i = 1;i <= GAMES_NUM;i++) {
            if (over[i]) continue;

            int w = winner(getShape(), getShape());
            if (w < 0) {
                win_cnt[i][0]++;
            } else if (w > 0) {
                win_cnt[i][1]++;
            }

            if (win_cnt[i][0] == 2) {
                won++;
                total_len += round;
                over[i] = 1;
            } else if (win_cnt[i][1] == 2) {
                lost++;
                total_len += round;
                over[i] = 1;
            }
        }
        total_over += (won + lost);
        total_win += won;
        printf("%6d games won and %6d games lost on round %2d.\n", won, lost, round);
    }
    printf("The chance of winning is %d/%d = %.2f%%\n", total_win, GAMES_NUM, (double)total_win/GAMES_NUM*100);
    printf("The average game length is %.2f rounds.\n", (double)total_len/GAMES_NUM);
    return 0;
}