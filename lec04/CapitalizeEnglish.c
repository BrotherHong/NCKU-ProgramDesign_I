#include<stdio.h>
#include<ctype.h>

int main(void) {
    int n;
    scanf("%d", &n);
    getchar(); // read '\n'
    while (n--) {
        char ch;
        int first = 1;
        while (1) {
            ch = getchar();
            if (ch == '.' || ch == ',' || ch == ';') {
                putchar('\n');
                break;
            }
            if (ch == ' ') {
                putchar(' ');
                first = 1;
            } else {
                if (first) {
                    putchar(toupper(ch));
                    first = 0;
                } else {
                    putchar(tolower(ch));
                }
            }
        }
    }
    return 0;
}