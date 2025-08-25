#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "my_sol.c"


static void test_basic() {
    assert(reverse_bits(0) == -1);
    assert(reverse_bits(-1) == 0);
}

static void test_patterns() {
    assert(reverse_bits(0xAAAAAAAA) == (int)0x55555555);
    assert(reverse_bits(0x55555555) == (int)0xAAAAAAAA);
}

static void test_examples() {
    assert(reverse_bits(0x12345678) == (int)0xEDCBA987);
    assert(reverse_bits(0xDEADBEEF) == (int)0x21524110);
}

int main(void) {
    test_basic();
    test_patterns();
    test_examples();

    printf("All reverse_bits tests passed!\n");
    return 0;
}