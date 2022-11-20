#include<stdio.h>
#include<ctype.h>
#define MAX_N 10005

struct String {
    int len;
    char str[MAX_N];
};

struct String addStr(struct String a, struct String b) {
    struct String result;
    result.len = 0;
    for (int i = 0;i < a.len;i++) {
        result.str[result.len++] = a.str[i];
    }
    for (int i = 0;i < b.len;i++) {
        result.str[result.len++] = b.str[i];
    }
    return result;
}

struct String inputString() {
    char ch;
    struct String result;
    result.len = 0;
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        result.str[result.len++] = ch;
    }
    return result;
}

void printString(struct String s) {
    for (int i = 0;i < s.len;i++) {
        putchar(s.str[i]);
    }
}

struct String intToHexStr(int n) {
    if (n == 0) {
        struct String result;
        result.len = 1;
        result.str[0] = '0';
        return result;
    }
    char tmp[MAX_N];
    int tlen = 0;
    while (n) {
        int r = n%16;
        tmp[tlen++] = (r >= 10 ? r-10+'a' : r+'0');
        n /= 16;
    }
    struct String result;
    result.len = 0;
    for (int i = tlen-1;i >= 0;i--) {
        result.str[result.len++] = tmp[i];
    }
    return result;
}

int hexToDec(char hex) {
    if ('0' <= hex && hex <= '9') {
        return hex - '0';
    }
    return hex - 'a' + 10;
}

struct String solve(struct String s) {
    if (s.len == 1) 
        return s;
    struct String even, odd;
    int iEven = 0, iOdd = 0;
    for (int i = 0;i < s.len;i++) {
        if (i%2 == 0) {
            iEven += hexToDec(s.str[i]);
        } else {
            iOdd += hexToDec(s.str[i]);
        }
    }
    even = intToHexStr(iEven);
    even = solve(even);

    odd = intToHexStr(iOdd);
    odd = solve(odd);

    return addStr(even, odd);
}

int main(void) {
    printString(solve(inputString()));
    return 0;
}