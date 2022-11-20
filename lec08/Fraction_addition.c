#include <stdio.h>
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,
              int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main() {
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
           &c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);
}

//

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr) {
    int c_top = a_numerator * b_denominator + b_numerator * a_denominator;
    int c_bott = a_denominator * b_denominator;
    int g = gcd(c_top, c_bott);
    *c_numerator_ptr = c_top / g;
    *c_denominator_ptr = c_bott / g;
}