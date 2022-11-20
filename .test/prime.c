#include<stdio.h>
#define MAX 10000

int prime[MAX+1];

int main(void) {
    // initialize
    for (int i = 0;i <= MAX;i++) {
        prime[i] = 1;
    }
    // build
    prime[0] = prime[1] = 0;
    for (int i = 2;i <= MAX;i++) {
        if (prime[i]) {
            for (int j = i*i;j <= MAX;j+=i) {
                prime[j] = 0;
            }
        }
    }
    // print
    for (int i = 0;i <= MAX;i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}