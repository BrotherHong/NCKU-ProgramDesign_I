#include<stdio.h>

void printBinary(unsigned int x) {
    unsigned int m = 0x80000000;
    for (int i = 1;i <= 32;i++) {
        if (i%8 == 1 && i != 1) {
            printf(" ");
        }
        printf("%1d", (x & m ? 1 : 0));
        m >>= 1;
    }
}

int main(void) {
    float a, b;
    scanf("%f%f", &a, &b);
    unsigned int *pa = &a;
    unsigned int *pb = &b;
    unsigned int sum = *pa + *pb;

    printf("   ");  printBinary(*pa); printf("\n");
    printf("+) ");  printBinary(*pb); printf("\n");
    printf("---------------------------------------\n");
    printf("   ");  printBinary(sum); printf("\n");
    printf("%d + %d = %d\n", (int)a, (int)b, (int)sum);

    return 0;
}

/*
   00111111 10000000 00000000 00000000
+) 01000000 00000000 00000000 00000000
---------------------------------------
   01111111 10000000 00000000 00000000
1 + 2 = 2139095040

*/