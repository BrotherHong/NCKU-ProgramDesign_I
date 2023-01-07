#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_MAX 2048
#define KEY_MAX 100

typedef struct search_s {
    char *key;
    char *value;
} search_t;

search_t *get_param_by_key(char *url, char *key);

int main ()
{
    char url[URL_MAX + 1], key[KEY_MAX + 1];

    fgets(url, URL_MAX, stdin);
    scanf("%s", key );

    search_t  *param = get_param_by_key (url, key);

    if (param)
        printf("key: %s, value: %s", param->key, param->value);
    else
        printf("404 Not Found");
}

//

char *getKey(char *s) {
    char *res = malloc(sizeof(char) * 105);
    int len = strlen(s);
    int idx = 0;
    for (int i = 0;i < len;i++) {
        if (s[i] == '=') {
            break;
        }
        res[idx++] = s[i];
    }
    res[idx] = '\0';
    return res;
}

char *getValue(char *s) {
    char *res = malloc(sizeof(char) * 105);

    int i = 0;
    int len = strlen(s);
    int idx = 0;

    while (s[i] != '=') i++;

    i += 1;

    for (;i < len;i++) {
        res[idx++] = s[i];
    }
    res[idx] = '\0';
    return res;
}

search_t *get_param_by_key (char *url, char *key) {
    search_t *result = malloc(sizeof(search_t));

    char *search = NULL;

    // find search position
    int len_url = strlen(url);
    for (int i = 0;i < len_url;i++) {
        if (url[i] == '?') {
            search = url + i + 1;
        }
        if (url[i] == '#' || url[i] == '\n') {
            url[i] = '\0';
        }
    }

    if (search == NULL) {
        return NULL;
    }

    // sep by &
    char *tok = strtok(search, "&");
    int found = 0;
    while (tok != NULL) {
        if (strcmp(key, getKey(tok)) == 0) {
            result->key = key;
            result->value = getValue(tok);
            found = 1;
            break;
        }
        tok = strtok(NULL, "&");
    }
    if (!found) {
        return NULL;
    }
    return result;
}