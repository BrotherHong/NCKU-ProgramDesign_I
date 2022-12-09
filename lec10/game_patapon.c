#include<stdio.h>
#include<string.h>
#define MAX_LEN 10000

/*
* PATA : 0
* PON : 1
* CHAKA : 2
*/

int mp(char *str) {
    if (strcmp(str, "PATA") == 0) return 0;
    if (strcmp(str, "PON") == 0) return 1;
    if (strcmp(str, "CHAKA") == 0) return 2;
    return -1;
}

/*
* 1: forward
* 2: attack
* 3: defend
* -1: no such command
*/
int getCommand(const char *str) {
    int cmd[4][4] = {
        {0},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {2, 2, 0, 1},
    };
    int my_cmd[4];
    int my_id = 0;
    char sub_cmd[10];
    int sub_id = 0;
    while (1) {
        if (*str == ' ' || *str == '\0') {
            sub_cmd[sub_id] = '\0';
            my_cmd[my_id++] = mp(sub_cmd);
            sub_id = 0;
        } else {
            sub_cmd[sub_id++] = *str;
        }
        if (*str == '\0') break;
        str++;
    }
    for (int c = 1;c <= 3;c++) {
        int match = 1;
        for (int i = 0;i < 4;i++) {
            if (cmd[c][i] != my_cmd[i]) {
                match = 0;
                break;
            }
        }
        if (match) return c;
    }
    return -1;
}

int main(void) {
    int distance, blood;
    scanf("%d%d\n", &distance, &blood);

    char input[MAX_LEN + 1];
    gets(input);

    int round = 0;
    int over = 0;
    int legal_cmd = 0;

    char *tok = strtok(input, ".,");
    while (tok != NULL) {
        int defense = 0;
        int cmd = getCommand(tok);
        // printf("%s : %d\n", tok, cmd);
        
        if (cmd != -1) legal_cmd++;
        switch (cmd) {
            case 1:
                distance--;
                break;
            case 2:
                if (distance <= 3) {
                    blood--;
                }
                break;
            case 3:
                distance++;
                defense = 1;
                break;
        }
        round++;
        if (blood == 0) {
            over = 1;
        }
        if (distance == 0) {
            over = 1;
        }
        if (round % 10 == 0) {
            if (!defense) {
                over = 1;
            }
        }
        if (over) break;
        tok = strtok(NULL, ".,");
    }
    if (blood == 0) { // player win
        printf("YES %d\n", legal_cmd);
    } else { // monster win
        printf("NO %d\n", blood);
    }
    return 0;
}