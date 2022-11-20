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

int ans[1500];
#define max(a, b) ((a) > (b) ? (a) : (b))

int maxChandy(int size) {
    ans[0] = array[0];
    ans[1] = max(array[0], array[1]);
    for (int i = 2;i < size;i++) {
        ans[i] = max(ans[i-2]+array[i], ans[i-1]);
    }
    return ans[size-1];

}