#include<stdio.h>

int depth;

int is_multiple_of_9(int n) {
    depth++;
    if (n < 10) {
        return (n == 9);
    }
    int sum = 0;
    while (n > 0) {
        sum += n%10;
        n /= 10;
    }
    return is_multiple_of_9(sum);
}

int main(void) {
    char input[1005];

    while (1) {
        int sum = 0;
        // input
        char ch;
        int idx = 0;
        while ((ch = getchar()) != '\n') {
            input[idx++] = ch;
            sum += (ch - '0');
        }
        input[idx] = '\0';
        // check for break
        if (sum == 0) break;
        // process
        depth = 0;
        if (is_multiple_of_9(sum)) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", input, depth);
        } else {
            printf("%s is not a multiple of 9.\n", input);
        }
    }
    return 0;
}