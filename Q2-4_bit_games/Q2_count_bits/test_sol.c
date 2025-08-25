#include "my_sol.c"
#include <assert.h>
#include <stdio.h>


static void test_zero() {
    assert(count_bits(0u) == 0);
}

static void test_one_bits() {
    assert(count_bits(1) == 1);
    assert(count_bits(2) == 1);
    assert(count_bits(4) == 1);
    assert(count_bits(8) == 1);
}

static void test_multiple_bits() {
    assert(count_bits(3) == 2);   // 11b
    assert(count_bits(7) == 3);   // 111b
    assert(count_bits(255) == 8); // 1111 1111b
}

static void test_large_values() {
    assert(count_bits(0xFFFFFFFF) == 32); // all bits set
    assert(count_bits(0x80000000) == 1);  // highest bit only
    assert(count_bits(0xF0F0F0F0) == 16); // alternating nibbles
}

static void test_random_examples() {
    assert(count_bits(0x12345678) == 13);
    assert(count_bits(0xDEADBEEF) == 24);
}

int main(void) {
    test_zero();
    test_one_bits();
    test_multiple_bits();
    test_large_values();
    test_random_examples();

    printf("All bit_count tests passed!\n");
    return 0;
}
