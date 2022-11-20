#include<stdio.h>

typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main(void) {
    int success = 0;
    char ch;
    Strength strength = INIT_STRENGTH;
    Obedience obedience = INIT_OBEDIENCE;
    while ((ch = getchar()) != '\n') {
        if (ch == 'e') {
            strength += STRENGTH_EAT;
            obedience -= OBEDIENCE_EAT;
        } else {
            strength -= STRENGTH_TRAIN;
            obedience += OBEDIENCE_TRAIN;
        }
        if (obedience >= LEARN_OBEDIENCE && strength <= LEARN_STRENGTH) {
            success++;
            obedience = INIT_OBEDIENCE;
        }
    }
    printf(success >= 5 ? "Yes" : "No");
    return 0;
}