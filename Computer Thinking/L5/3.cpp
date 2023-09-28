#include <stdio.h>
#include <stdlib.h>

/// Requirements: print sum of 0 to 99.

int main() {
    int i = 0, sum = 0;
    for(;i < 100; i += 1) {
        sum = sum + i;
    }
    printf("%d", sum);
}