#include<stdio.h>
#include<stdlib.h>
int array[1500];
int maxChandy( int size) ;
int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy( size));
    return 0;
}

//

int dp[45] = {0};

int maxChandy(int size) {
    if (size == 0)
        return 0;
    if (size == 1)
        return array[0];
    int idx = size-1;
    if (dp[idx] != 0)
        return dp[idx];
    int a = array[idx] + maxChandy(size-2);
    int b = maxChandy(size-1);
    return dp[idx] = (a > b ? a : b);
}
