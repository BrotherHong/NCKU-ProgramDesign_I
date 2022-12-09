#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

//

Location *parse_url(char *url) {
    // init result
    Location *res = malloc(sizeof(Location));
    res->port = 0;
    char *empty = res->pathname = res->search = res->hash = malloc(1);
    *empty = '\0';

    // some var
    char *p = url;
    int len;

    // protocal
    while (*p != ':') p++;
    len = p - url;
    res->protocol = malloc(len + 1);
    for (int i = 0;i < len;i++) {
        res->protocol[i] = url[i];
    }
    res->protocol[len] = '\0';

    // move to data head (now p point to ':') (skip "://")
    // so
    p += 3;
    url = p;

    // host (end with :/?# or \n)
    while (*p != ':' && *p != '/' && *p != '?' 
            && *p != '#' && *p != '\n') p++;
    len = p - url;
    res->host = malloc(len + 1);
    for (int i = 0;i < len;i++) {
        res->host[i] = url[i];
    }
    res->host[len] = '\0';

    // check head
    char head = *p;
    if (head == '\n') return res;

    // port (optional)
    if (head == ':') {
        // move to data head
        p += 1;
        url = p;
        // get data
        while (*p != '/' && *p != '?' && *p != '#' && *p != '\n') p++;
        len = p - url;
        for (int i = 0;i < len;i++) {
            res->port = res->port*10 + (url[i] - '0');
        }
    }

    // chekc head
    head = *p;
    if (head == '\n') return res;

    // path (optional)
    if (head == '/') {
        // move to data head
        p += 1;
        url = p;
        // get data
        while (*p != '?' && *p != '#' && *p != '\n') p++;
        len = p - url;
        res->pathname = malloc(len + 1);
        for (int i = 0;i < len;i++) {
            res->pathname[i] = url[i];
        }
        res->pathname[len] = '\0';
    }

    // chekc head
    head = *p;
    if (head == '\n') return res;

    // search (optional)
    if (head == '?') {
        // move to data head
        p += 1;
        url = p;
        // get data
        while (*p != '#' && *p != '\n') p++;
        len = p - url;
        res->search = malloc(len + 1);
        for (int i = 0;i < len;i++) {
            res->search[i] = url[i];
        }
        res->search[len] = '\0';
    }

    // chekc head
    head = *p;
    if (head == '\n') return res;

    // hash (optional)
    if (head == '#') {
        // move to data head
        p += 1;
        url = p;
        // get data
        while (*p != '\n') p++;
        len = p - url;
        res->hash = malloc(len + 1);
        for (int i = 0;i < len;i++) {
            res->hash[i] = url[i];
        }
        res->hash[len] = '\0';
    }

    // return result
    return res;
}