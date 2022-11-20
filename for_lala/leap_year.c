#include<stdio.h>

int isLeapYear(int year) {
    return (year%400 == 0 || (year%4 == 0 && year%100 != 0));
}

int main(void) {
    int data[10] = {1961, 2171, 2007, 1947, 2016, 2163, 1933, 2199, 1924, 2107};
    for (int i = 0;i < 10;i++) {
        if (isLeapYear(data[i])) {
            printf("%d is leap year.\n", data[i]);
        }
    }
    return 0;
}

/* output should be
    2016 is leap year.
    1924 is leap year.
*/