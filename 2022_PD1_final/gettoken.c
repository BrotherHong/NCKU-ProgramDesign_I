#include <stdio.h>
#include <stdlib.h>

char *strtok(char *s, const char *sep)
{
    printf("strtok banned\n");
    exit(1);
}
char *strtok_r(char *str, const char *sep, char **lasts)
{
    printf("strtok_r banned\n");
    exit(1);
}

char *strsep(char **stringp, const char *delim)
{
    printf("strsep banned\n");
    exit(1);
}
char *gettoken(char *str, const char *sep);
int main()
{
    char buffer[4096];
    char *sep = " \t\n;,.?!";
    char *word;
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
    {
        fgets(buffer, 4095, stdin);
        for (word = gettoken(buffer, sep); word != NULL;
             word = gettoken(NULL, sep))
        {
            printf("%s\n", word);
        }
    }
}

//

char *p;

int contain(const char *src, const char target) {
    int len = 8;
    for (int i = 0;i < len;i++) {
        if (src[i] == target) {
            return 1;
        }
    }
    return 0;
}

char *gettoken(char *str, const char *sep) {
    if (str != NULL) {
        p = str;
    }
    while (contain(sep, *p)) {
        p++;
    }
    if (*p == '\0') {
        return NULL;
    }
    char *head = p;
    while (!contain(sep, *p)) {
        p++;
    }
    *p = '\0';
    p++;
    return head;
}

/*
2
When I wrote this code, only God and I understood what I did. Now... only God knows.
C programmers never die. They are just cast into void.

*/