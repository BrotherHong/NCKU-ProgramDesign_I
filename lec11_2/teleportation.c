#include <stdio.h>

unsigned long long construct(unsigned char parts[16]);

int main() {
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%llu", construct(parts));

    return 0;
}

//

typedef union {
    
    struct {
        unsigned long long l1;
        unsigned long long l2;
    } l;

    unsigned char p[16];
} U;

unsigned long long construct(unsigned char parts[16]) {
    U u;
    for (int i = 0;i < 16;i++) {
        u.p[i] = parts[i];
    }
    return u.l.l1 ^ u.l.l2;
}
