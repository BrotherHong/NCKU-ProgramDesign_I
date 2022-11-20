#include<stdio.h>

int main(){
    freopen("input.in", "r", stdin);
    
    int x, y, z;

    while (scanf("%d %d", &x, &y) != EOF) {
        if(x % y == 0 || y % x == 0) {
            if(x > y) {
                z = 364 / x + 1 ; //剩下的364天要請的數量+1
            }
            else {
                z = 364 / y + 1 ;
            }
        }
        else {
            z = 364 / ( x * y ) + 1 ;
        }
        printf ("%d\n", z) ;

    }

 }