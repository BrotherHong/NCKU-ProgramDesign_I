#include<stdio.h>
#include<ctype.h>

int hexToInt(char c) {
    if (isalpha(c)) {
        return c-'a'+10;
    }
    return c-'0';
}

char intToHex(int n) {
    if (n >= 10) {
        return n - 10 + 'a';
    }
    return n + '0';
}

void intToHexStr(int num, char result[], int *len) {
    if (num == 0) {
        result[0] = '0';
        *len = 1;
        return;
    }
    char tmp[10001];
    int tmp_len = 0;
    while (num) {
        tmp[tmp_len++] = intToHex(num%16);
        num /= 16;
    }
    for (int i = tmp_len-1;i >= 0;i--) {
        result[(*len)++] = tmp[i];
    }
}

void solve(char input[], int input_len, char result[], int *result_len) {
    if (input_len == 1) {
        result[0] = input[0];
        *result_len = 1;
        return;
    }
    // calc sum
    int even_sum = 0, odd_sum = 0;
    for (int i = 0;i < input_len;i++) {
        if (i%2 == 0) {
            even_sum += hexToInt(input[i]);
        } else {
            odd_sum += hexToInt(input[i]);
        }
    }

    // generate new string
    char even_str[10001];
    int even_len = 0;
    char odd_str[10001];
    int odd_len = 0;

    intToHexStr(even_sum, even_str, &even_len);
    intToHexStr(odd_sum, odd_str, &odd_len);

    // solve and return
    char even_res[10001];
    int even_res_len = 0;
    char odd_res[10001];
    int odd_res_len = 0;

    solve(even_str, even_len, even_res, &even_res_len);
    solve(odd_str, odd_len, odd_res, &odd_res_len);

    int rlen = 0;
    for (int i = 0;i < even_res_len;i++) {
        result[rlen++] = even_res[i];
    }
    for (int i = 0;i < odd_res_len;i++) {
        result[rlen++] = odd_res[i];
    }
    *result_len = rlen;
}

int main(void) {
    char init_input[10001];
    int init_len = 0;
    // input init input
    char ch;
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        init_input[init_len++] = ch;
    }
    char ans[10001];
    int len = 0;
    solve(init_input, init_len, ans, &len);
    for (int i = 0;i < len;i++) {
        printf("%c", ans[i]);
    }
    return 0;
}