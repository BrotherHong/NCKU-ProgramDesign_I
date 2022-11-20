#include<stdio.h>
#define BYTE_BITS 8u
#define MAX_BYTE 4u
typedef unsigned int uInt;

uInt getKthByte(uInt N, uInt Kth) {
    return (N >> ((MAX_BYTE-Kth)*BYTE_BITS)) % (1 << BYTE_BITS);
}

uInt storeAtKthByte(uInt dest, uInt src, uInt Kth) {
    return dest | (src << ((MAX_BYTE-Kth)*BYTE_BITS));
}

int main(void) {
    uInt N, d1, d2, d3, d4;
    scanf("%u", &N);
    scanf("%u%u%u%u", &d1, &d2, &d3, &d4);
    uInt temp = 0;
    temp = storeAtKthByte(temp, (getKthByte(N, d1) ^ getKthByte(N, d2)) % (1 << BYTE_BITS), 1u);
    temp = storeAtKthByte(temp, (getKthByte(N, d2) & getKthByte(N, d3)) % (1 << BYTE_BITS), 2u);
    temp = storeAtKthByte(temp, (getKthByte(N, d3) | getKthByte(N, d1) % (1 << BYTE_BITS)), 3u);
    temp = storeAtKthByte(temp, (~getKthByte(N, d4)) % (1 << BYTE_BITS), 4u);
    uInt rotate = d1 + d2 + d3 + d4;
    temp = (temp >> rotate) | ((temp % (1 << rotate)) << (MAX_BYTE*BYTE_BITS - rotate));
    temp = (temp >> 16) ^ (temp % (1 << 16));
    printf("%u", temp);
    return 0;
}