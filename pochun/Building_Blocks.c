#include<stdio.h>

int main(void) {
    int set = 0;
    int n;
    int arr[50];
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        set++;
        int total = 0;
        for (int i = 0;i < n;i++) {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        int h = total / n;
        int moves = 0;
        for (int i = 0;i < n;i++) {
            if (arr[i] > h) {
                moves += arr[i] - h;
            }
        }
        printf("Set #%d\n", set);
        printf("The minimum number of moves is %d.\n", moves);
        printf("\n");
    }
    return 0;
}