typedef struct {
    char address[6];
} mac_address;


bool macs_equal(mac_address* add1, mac_address* add2){
    return (((int*)add1->address) == ((int*)add2->address) &&
           ((short*)(add1->address + 4)) == (short*)(add2->address + 4));
}