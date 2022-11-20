#include<stdio.h>

int hexToInt(char hex) {
    if ('0' <= hex && hex <= '9') {
        return hex - '0';
    }
    return hex - 'a' + 10;
}

int main(void) {
    for (int i = 1;i <= 4;i++) {
        if (i != 1) {
            printf(".");
        }
        char f, s;
        f = getchar();
        s = getchar();
        printf("%d", hexToInt(f)*16 + hexToInt(s));
    }
    return 0;
}