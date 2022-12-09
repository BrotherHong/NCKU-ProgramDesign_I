#include<stdio.h>
#include<string.h>

int main(void) {
    char str[] = "https://www.abc.com:80/user/12345/photo?from=20180101&to=20201231#favorite";
    char *tok = strtok(str, ":/?#");
    while (tok != NULL) {
        printf("%s\n", tok);
        tok = strtok(NULL, ":/?#");
    }
    return 0;
}