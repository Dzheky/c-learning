#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

unsigned invert(unsigned x, int p, int n);
unsigned getportion(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);
unsigned cutbitsout(unsigned x, int p, int n);

int main() {
    unsigned b = 0b01110111;

    unsigned result = invert(0b01010101, 0, 8);

    printf("bynary: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(result));

    return 0;
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned getportion(unsigned x, int p, int n) {
    return ~(~0 << n) << p & x;
}

unsigned invert(unsigned x, int p, int n) {
    unsigned toReverse = getportion(x, p , n);
    unsigned result = cutbitsout(x, p, n);
    for (int i = 0; i < n; i++) {
        unsigned test = getbits(toReverse, p + i, 1) << (p + n - i - 1);
        result = result | test;
    }
    return result;
}

unsigned cutbitsout(unsigned x, int p, int n) {
    unsigned mask = ~getportion(~0, p, n);

    return x & mask;
}