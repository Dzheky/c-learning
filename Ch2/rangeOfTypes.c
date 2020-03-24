/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>

#define SHORT_INT 16
#define INT 32 // or in some cases 16
#define LONG_INT 32
enum type { SIGNED, UNSIGNED };

float calculateRange(int bits, int isSigned);

int main() {
    printf("signed char: \t\t%.0f\t\t%.0f\n", -calculateRange(CHAR_BIT, SIGNED), calculateRange(CHAR_BIT, SIGNED));
    printf("unsigned char: \t\t%.0f\t\t%.0f\n", 0.0, calculateRange(CHAR_BIT, UNSIGNED));
    printf("signed short int: \t%.0f\t\t%.0f\n", -calculateRange(SHORT_INT, SIGNED), calculateRange(SHORT_INT, SIGNED));
    printf("unsigned short int: \t%.0f\t\t%.0f\n", 0.0, calculateRange(SHORT_INT, UNSIGNED));
    printf("signed int: \t\t%.0f\t%.0f\n", -calculateRange(INT, SIGNED), calculateRange(INT, SIGNED));
    printf("unsigned int: \t\t%.0f\t\t%.0f\n", 0.0, calculateRange(INT, UNSIGNED));
    printf("signed long int: \t%.0f\t%.0f\n", -calculateRange(LONG_INT, SIGNED), calculateRange(LONG_INT, SIGNED));
    printf("unsigned long int: \t%.0f\t\t%.0f\n", 0.0, calculateRange(LONG_INT, UNSIGNED));

    return 0;
}

float calculateRange(int bits, int isSigned) {
    if (isSigned == SIGNED) {
        return pow(2, bits - 1) - 1;
    }

    return pow(2, bits) - 1;
}