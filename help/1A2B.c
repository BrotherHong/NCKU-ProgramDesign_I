#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define NUMBER_OF_DIGIT 4

typedef int RoleType;
#define HOST 1
#define GUESS 2

typedef int Bool;
#define TRUE 1
#define FALSE 0

void PC_Guess();
void PC_Host();

// for pc host
void generate_answer(char[]);

// for pc guess
void generate_all_possible(char [][NUMBER_OF_DIGIT+5], int*);

// for both mode
void get_input_AB(char[], const char[], int*, int*);
Bool check_input_legal(char[]);



int main(void) {
    int player_role = -1;

    // select role
    while (TRUE) {
        printf("Guess or host? (1: host/ 2: guess): ");
        RoleType input;
        scanf("%d", &input);

        // printf("TEST");

        if (input == GUESS) {
            player_role = GUESS;
            break;
        }
        else if (input == HOST) {
            player_role = HOST;
            break;
        }
        else {
            printf("Wrong input.\n");
        }
    }

    // game start
    Bool over = FALSE;
    while (!over) { // not over
        if (player_role == HOST) {
            PC_Guess();
        } else if (player_role == GUESS) {
            PC_Host();
        }
        
        // ask again
        while (TRUE) {
            printf("Play again? (1: yes/ 0: no): ");
            Bool input;
            scanf("%d", &input);

            if (input == TRUE) {
                over = FALSE;
                break;
            }
            else if (input == FALSE) {
                over = TRUE;
                break;
            }
            else {
                printf("Wrong input.\n");
            }
        }
    }
    return 0;
}

// PC host
void PC_Host() {
    // generate answer
    char answer[NUMBER_OF_DIGIT+5];
    generate_answer(answer);
    printf("Answer: %s\n", answer);

    // running main
    while (TRUE) {
        // get player input
        char input[NUMBER_OF_DIGIT+5];
        while (TRUE) {
            printf("Input: ");
            scanf("%s", input);
            Bool legal = check_input_legal(input);
            if (!legal) {
                printf("Wrong input.\n");
            } else break;
        }

        // check A B
        int A = 0, B = 0;
        // printf("Answer: %d %d %d %d\n", answer[0], answer[1], answer[2], answer[3]);
        get_input_AB(input, answer, &A, &B);
        printf("Result: %dA%dB\n", A, B);

        // check over
        if (A == NUMBER_OF_DIGIT) {
            printf("YOU WIN\n");
            break;
        }
    }

}

void generate_answer(char result[]) {
    Bool used[10] = {FALSE};
    srand(time(NULL));
    for (int i = 0;i < NUMBER_OF_DIGIT;i++) {
        while (TRUE) {
            int r = rand() % 10;
            if (used[r]) continue;
            used[r] = TRUE;
            result[i] = (char) (r + '0');
            break;
        }
    }
}

void get_input_AB(char input[], const char answer[], int *A, int *B) {
    // printf("%s\n%s\n", answer, input);
    for (int i = 0;i < NUMBER_OF_DIGIT;i++) {
        for (int j = 0;j < NUMBER_OF_DIGIT;j++) {
            if (answer[i] == input[j]) {
                if (i == j) {
                    (*A) += 1;
                } else {
                    (*B) += 1;
                }
            }
            // printf("%d %d -> %dA %dB\n", i, j, *A, *B);
        }
    }
}

Bool check_input_legal(char input[]) {
    Bool used[10] = {FALSE};
    for (int i = 0;i < NUMBER_OF_DIGIT;i++) {
        if (!isdigit(input[i])) {
            return FALSE;
        }
        if (used[input[i]-'0'])
            return FALSE;
        used[input[i]-'0'] = TRUE;
    }
    return TRUE;
}

// PC guess
void PC_Guess() {
    char psb[10005][NUMBER_OF_DIGIT+5];
    int len = 0;
    generate_all_possible(psb, &len);
    Bool win = FALSE;
    while (len > 0) {
        // print pc answer
        printf("PC responds: %s\n", psb[0]);

        // get result
        int result_A, result_B;
        printf("Input the result: ");
        scanf("%1dA%1dB", &result_A, &result_B);

        // check win
        if (result_A == NUMBER_OF_DIGIT) {
            win = TRUE;
            break;
        }

        // remove impossible result
        //// copy to tmp
        char tmp[10005][NUMBER_OF_DIGIT+5];
        int tmp_len = len;
        for (int i = 0;i < len;i++) {
            for (int j = 0;j < NUMBER_OF_DIGIT;j++) {
                tmp[i][j] = psb[i][j];
            }
        }
        //// save possible result
        len = 0;
        for (int i = 0;i < tmp_len;i++) {
            int a = 0, b = 0;
            get_input_AB(tmp[i], tmp[0], &a, &b);
            if (a == result_A && b == result_B) {
                for (int j = 0;j < NUMBER_OF_DIGIT;j++) {
                    psb[len][j] = tmp[i][j];
                }
                len++;
            }
        }

    }

    printf("%s\n", (win ? "YEAH" : "CHEAT!"));
}

void generate_all_possible(char arr[][NUMBER_OF_DIGIT+5], int *len) {
    char tmp[NUMBER_OF_DIGIT+5];
    int n = 0;
    for (int a = 0;a <= 9;a++) {
        for (int b = 0;b <= 9;b++) {
            for (int c = 0;c <= 9;c++) {
                for (int d = 0;d <= 9;d++) {
                    tmp[0] = a + '0';
                    tmp[1] = b + '0';
                    tmp[2] = c + '0';
                    tmp[3] = d + '0';
                    // check
                    if (check_input_legal(tmp)) {
                        // copy
                        for (int i = 0;i < NUMBER_OF_DIGIT;i++) {
                            arr[n][i] = tmp[i];
                        }
                        n++;
                    }
                }
            }
        }
    }
    *len = n;
}
