#include<stdio.h>
#include<ctype.h>

double gp[10] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 0};

double getPoints(char letter, char option) {
    // letter: A, B, C, F
    // option: '+', ' ', '-'
    int p = (option == '+' ? 0 : (option == ' ' ? 1 : 2));
    switch (letter) {
        case 'A':
            return gp[p];
        case 'B':
            return gp[3+p];
        case 'C':
            return gp[6+p];
        case 'F':
            return gp[9];
    }
    return 0;
}

int main(void) {
    int totalCredit = 0;
    double totalSum = 0;
    char ch;

    int credit = 0;
    char curLetter = ' ';
    char curOption = ' ';
    while ((ch = getchar()) != '\n') {
        if (isdigit(ch)) {
            if (curLetter != ' ') {
                // calculate
                totalSum += credit * getPoints(curLetter, curOption);
                totalCredit += credit;
                credit = 0;
                curLetter = ' ';
                curOption = ' ';
            }
            credit = credit*10 + (ch - '0');
        } else if (ch == '+' || ch == '-') {
            curOption = ch;
        } else {
            curLetter = ch;
        }
    }
    // calculate the last input
    totalSum += credit * getPoints(curLetter, curOption);
    totalCredit += credit;
    // print the result
    printf("%.2f", totalSum / totalCredit);
    return 0;
}