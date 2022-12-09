#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_LEN 500

void tolower_str(char *s) {
    while (*s != '\0') {
        *s = tolower(*s);
        s++;
    }
}

int main(void) {
    // freopen("../input.in", "r", stdin);

    char *shi[MAX_LEN];
    int len_shi = 0;

    char str[MAX_LEN+1];
    fgets(str, MAX_LEN+1, stdin);

    // fgets stop if a newline char is found
    // and will contain that newline char
    // so delimiter must have '\n'

    char *tok = strtok(str, ",\n");
    while (tok != NULL) {
        tolower_str(tok);
        shi[len_shi++] = tok;
        tok = strtok(NULL, ",\n");
    }

    char input[MAX_LEN+1];
    while (fgets(input, MAX_LEN+1, stdin) != NULL) {
        char *tk = strtok(input, ",\n");
        int cnt = 0;
        while (tk != NULL) {
            tolower_str(tk);
            for (int i = 0;i < len_shi;i++) {
                if (strcmp(shi[i], tk) == 0) { // if equal
                    cnt++;
                    break;
                }
            }
            tk = strtok(NULL, ",\n");
        }
        if (cnt == 0) {
            printf("SAFE");
        } else if (cnt <= 2) {
            printf("WARNING");
        } else {
            printf("DNAGER");
        }
        printf("\n");
    }
    return 0;
}
