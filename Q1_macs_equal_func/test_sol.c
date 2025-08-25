#include <stdio.h>
#include <assert.h>

#include "my_solution.c"

static void print_mac(const mac_address* m) {
    const unsigned char* a = (const unsigned char*)m->address;
    printf("%02X:%02X:%02X:%02X:%02X:%02X",
        a[0], a[1], a[2], a[3], a[4], a[5]);
}

static void test_equal() {
    mac_address a = { .address = {0x00,0x11,0x22,0x33,0x44,0x55} };
    mac_address b = { .address = {0x00,0x11,0x22,0x33,0x44,0x55} };
    assert(macs_equal(&a, &b) && "Equal MACs should compare equal");
}

static void test_diff_first4() {
    mac_address a = { .address = {0xDE,0xAD,0xBE,0xEF,0x00,0x01} };
    mac_address b = { .address = {0xFE,0xED,0xFA,0xCE,0x00,0x01} };
    assert(!macs_equal(&a, &b) && "Different in first 4 bytes should be false");
}

static void test_diff_last2() {
    mac_address a = { .address = {0xAA,0xBB,0xCC,0xDD,0xEE,0xFF} };
    mac_address b = { .address = {0xAA,0xBB,0xCC,0xDD,0xEE,0xFE} };
    assert(!macs_equal(&a, &b) && "Different in last 2 bytes should be false");
}

static void test_zero_and_max() {
    mac_address zero = { .address = {0,0,0,0,0,0} };
    mac_address zero2 = { .address = {0,0,0,0,0,0} };
    mac_address max = { .address = {255,255,255,255,255,255} };
    assert(macs_equal(&zero, &zero2));
    assert(!macs_equal(&zero, &max));
}

int main(void) {
    printf("Running MAC equality tests...\n");

    test_equal();
    test_diff_first4();
    test_diff_last2();
    test_zero_and_max();

    printf("All tests passed.\n");
    return 0;
}
