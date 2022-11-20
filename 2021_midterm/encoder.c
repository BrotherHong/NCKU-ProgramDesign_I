#include<stdio.h>

int main(void) {
    char c;
    char type;
    int k;
    scanf("%d", &k);
    scanf(" %c ", &type);
    while (scanf("%c", &c)) {
        if (c == '\n') break;
        k %= 26;
        k = (k < 0 ? k+26 : k);
        if ('a' <= c && c <= 'z') {

            printf("%c", (c-'a'+k)%26 + 'a');
            k += (type == 'a' ? 1 : -1);

        } else if ('A' <= c && c <= 'Z') {

            printf("%c", (c-'A'+k)%26 + 'A');
            k += (type == 'a' ? 1 : -1);

        } else {
            printf("%c", c);
        }
    }
    return 0;
}