#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}

//

int isLegalWord(char*);

void recovery(char *homework) {
    char result[MAX_LEN + 1] = {'\0'};
    char *tok = strtok(homework, " \n");
    int first = 1;
    while (tok != NULL) {
        // todo
        if (isLegalWord(tok)) {
            if (!first) {
                strcat(result, " ");
            } else first = 0;
            strcat(result, tok);
        }
        //
        tok = strtok(NULL, " \n");
    }
    strcpy(homework, result);
}

int isLegalWord(char *word) {
    int len = strlen(word);

    if (!(1 <= len && len <= 21)) {
        return 0;
    }

    for (int i = 0;i < len;i++) {
        char ch = word[i];
        if (isalpha(ch)) continue;
        if (ch == '.' || ch == ',' || ch == '!' || ch == '?') {
            if (len != 1 && i == len-1) continue;
            else return 0;
        } else {
            return 0;
        }
    }
    return 1;
}