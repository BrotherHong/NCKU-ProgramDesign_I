#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 15

void convert (char *last, char *first);

int main()
{
    char last_name[MAX_LEN + 2];
    char first_name[MAX_LEN + 2];
    
    // Enter last name
    fgets(last_name, MAX_LEN*2 , stdin);
    if(last_name[strlen(last_name) - 1] == '\n')
        last_name[strlen(last_name) - 1] = '\0';
    
    // Enter first name
    fgets(first_name, MAX_LEN*2, stdin);
    if(first_name[strlen(first_name) - 1] == '\n')
        first_name[strlen(first_name) - 1] = '\0';
    
    // Convert and print the name by using the function convert
    convert(last_name, first_name);
    
    return 0;
}

// upload line

int check(char *s) {
    int len = strlen(s);
    int hasWhite = 0;
    for (int i = 0;i < len;i++) {
        if (s[i] == ' ') {
            hasWhite = 1;
        }
    }
    if (hasWhite) {
        return len <= 16;
    }
    return len <= 15;
}

void convert (char *last, char *first) {
    if (!check(last) || !check(first)) {
        printf("illegal");
        return;
    }
    char result[50];
    int idx = 0;
    for (int i = 0;i < strlen(last);i++) {
        result[idx++] = toupper(last[i]);
    }
    result[idx++] = ',';
    result[idx++] = ' ';
    for (int i = 0;i < strlen(first);i++) {
        if (first[i] == ' ') {
            result[idx++] = '-';
            continue;
        }
        result[idx++] = toupper(first[i]);
    }
    result[idx] = '\0';
    printf("%s", result);
}