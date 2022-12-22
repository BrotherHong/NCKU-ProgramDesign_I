#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    FILE *output = fopen("output.txt", "r");
    FILE *answer = fopen("answer.txt", "r");
    char str1[100], str2[100];
    int ac = 1;
    while (fgets(str1, 100, answer) != NULL) {
        fgets(str2, 100, output);
        if (strcmp(str1, str2) != 0) {
            ac = 0;
            break;
        }
    }
    printf("%s\n", (ac ? "AC" : "WA"));
    return 0;
}