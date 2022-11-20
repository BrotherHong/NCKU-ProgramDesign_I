#include<stdio.h>
typedef unsigned long long int ull;

int main(void) {
    ull MOD = 0x7CE66C50E2840000ULL;
    ull NUMBER_1 = 0x38E38E38E38E3800ULL % MOD;
    ull NUMBER_2 = 0x2AAAAAAAAAAAAAAAULL % MOD;
    ull NUMBER_3 = 0x1C71C71C71C71C71ULL % MOD;
    ull d1, d2, d3;
    scanf("%llu%llu%llu", &d1, &d2, &d3);
    ull result = ((d1*NUMBER_1%MOD + d2*NUMBER_2%MOD) % MOD + d3*NUMBER_3%MOD) % MOD;
    printf("%llu", result);
    return 0;
}