#include <stdio.h>
#include <assert.h>
#include "my_sol.c"

static void test_zero() {
    int upper, lower;
    int_half(0, &lower, &upper);
    assert(upper == 0);
    assert(lower == 0);
}

static void test_simple() {
    int upper, lower;
    int_half(0x12345678, &lower, &upper);
    assert(upper == 0x1234);
    assert(lower == 0x5678);
}

static void test_all_ones() {
    int upper, lower;
    int_half(-1, &lower, &upper);   // 0xFFFFFFFF
    assert(upper == 0xFFFF);
    assert(lower == 0xFFFF);
}

static void test_upper_only() {
    int upper, lower;
    int_half(0xABCD0000, &lower, &upper);
    assert(upper == 0xABCD);
    assert(lower == 0x0000);
}

static void test_lower_only() {
    int upper, lower;
    int_half(0x0000BEEF, &lower, &upper);
    assert(upper == 0x0000);
    assert(lower == 0xBEEF);
}

int main(void) {
    test_zero();
    test_simple();
    test_all_ones();
    test_upper_only();
    test_lower_only();

    printf("All int_half tests passed!\n");
    return 0;
}
