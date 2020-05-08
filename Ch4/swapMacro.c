#include <stdio.h>

#define swap(t,x,y) { t _holder = x; x = y; y = _holder; }

int main() {
    int z = 1;
    int k = 15;
    printf("z = %d, k = %d\n", z, k);
    swap(int, z, k);
    printf("z = %d, k = %d\n", z, k);
    return 0;
}