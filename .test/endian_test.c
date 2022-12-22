#include<stdio.h>

typedef union {
    long int l;
    char c[4];
} EndianTest;

int main(void) {
    EndianTest et;
    et.l = 0x12345678;
    for (int i = 0;i < 4;i++) {
        printf("0x%x ", et.c[i]);
    }
    return 0;
}