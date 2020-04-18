#include <stdio.h>

int bitcount(unsigned x);

int main() {

    printf("%d\n", bitcount(0b01110111));

    return 0;
}

int bitcount(unsigned x) {
    int count = 0;
    while (x) {
        x &= x - 1;
        count++;
    }

    return count;
}