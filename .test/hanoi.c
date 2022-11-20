#include<stdio.h>

void hanoi(int n, char src, char aux, char dest) {
    if (n == 0) {
        return;
    }
    hanoi(n-1, src, dest, aux);
    printf("move disk %d from %c to %c\n", n, src, dest);
    hanoi(n-1, aux, src, dest);
}

int main(void) {
    int N = 4;
    hanoi(4, 'A', 'B', 'C');
    return 0;
}