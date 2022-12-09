#include<stdio.h>
#include<ctype.h>

int mp[26] = {0, 1, 2, 3, 4, 4, -1, 6, 7, 8, 9, 0, -1, 2, -1, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, 2};

int main(void) {
    /*
    for (int i = 0;i < 26;i++) {
        printf("%c %d\n", i+'A', mp[i]);
    }
    */
    int found = 0;
    char ans[10];
    while (1) {
        char ch = getchar(); // alpha
        if (ch == '\n') break;

        char id[10]; // 1-indexed ~ 9
        id[1] = ch;

        // input num
        for (int i = 2;i <= 9;i++) {
            id[i] = getchar();
        }

        getchar(); // '\n'

        if (found) continue;

        // calc
        int sum = mp[toupper(id[1])-'A'] * 9;
        for (int i = 9;i >= 2;i--) {
            sum += (id[i]-'0')*(9-i+1);
        }  

        // check
        if (sum % 10 != 0) {
            found = 1;
            for (int i = 1;i <= 9;i++) {
                ans[i] = id[i];
            }
        }
    }
    for (int i = 1;i <= 9;i++) {
        printf("%c", ans[i]);
    }
    printf(" is the imposter!!!\n");
    return 0;   
}