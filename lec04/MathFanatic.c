#include<stdio.h>
#define MAX 100000

int arr[MAX+5];
long long psum[MAX+5];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
        psum[i] = arr[i] + (i > 0 ? psum[i-1] : 0);
    }
    for (int i = 0;i < n;i++) {
        if (psum[i] % arr[i] == 0) {
            printf("%lld %d\n", psum[i], arr[i]);
        }
    }
    return 0;
}