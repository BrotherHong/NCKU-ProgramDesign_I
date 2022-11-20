#include<stdio.h>
#include<string.h>

int main(void) {
    // printf("%d", strlen("¾Ç"));
    char a[] = "¾Ç";
    printf("%d\n", strlen(a));
    printf("%d %d\n", a[0], a[1]);
    char b[3] = {-66, -57};
    printf("%s\n", b);
    return 0;
}