#include<stdio.h>
#include<ctype.h>

int key[100];

int main(void) {
    int len;
    scanf("%d", &len);
    getchar(); // read '\n'
    for (int i = 0;i < len;i++) {
        char k = getchar();
        key[i] = k-'a';
    }
    getchar(); // read '\n'
    char ch;
    int kid = 0;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = (ch-'A'+key[kid])%26 + 'A';
            } else { // islower
                ch = (ch-'a'+key[kid])%26 + 'a';
            }
            // update kid
            kid = (kid+1) % len;
        }
        putchar(ch);
    }
    return 0;
}