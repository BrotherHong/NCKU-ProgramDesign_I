#include<stdio.h>
#include<ctype.h>

struct Student {
    int len;
    char name[20];
};

struct Student stu[35];

int isALowerThanB(struct Student a, struct Student b) {
    int len = (a.len < b.len ? a.len : b.len);
    for (int i = 0;i < len;i++) {
        if (tolower(a.name[i]) < tolower(b.name[i])) {
            return 1;
        } else if (tolower(a.name[i]) > tolower(b.name[i])) {
            return 0;
        }
    }
    return a.len < b.len;
}

int main(void) {
    int N;
    scanf("%d", &N);
    // trans student -> index == 0
    for (int i = 0;i <= N;i++) {
        scanf("%d %s", &stu[i].len, stu[i].name);
    }
    int lower = 0; // how many students lower than trans stu

    for (int i = 1;i <= N;i++) {
        if (isALowerThanB(stu[i], stu[0])) {
            lower++;
        }
    }

    // answer is lower+1
    printf("%d", lower+1);
    return 0;
}