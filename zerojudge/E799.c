#include<stdio.h>
typedef unsigned long long ull;

int main(void) {
    int N, M;
    scanf("%d%d", &N, &M);
    getchar(); // read '\n'
    char c = getchar();
    while (N--) {
        ull num;
        scanf("%llu", &num);
        for (int i = M-1;i >= 0;i--) {
            if (num & (1LLU << i)) {
                printf("%c ", c);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    return 0;
}