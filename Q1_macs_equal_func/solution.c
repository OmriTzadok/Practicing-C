typedef struct {
	char addres[6];
} mac_address;


bool macs_equal(mac_address* add1, mac_address* add2){
	// Compare first 4 byte as int
	int* ip1 = (int*)add1->address;
	int* ip2 = (int*)add2->address;

	if (ip1* != ip2*) return false;

	 
	// Compare last 2 bytes as short
    	short* sp1 = (short*)(add1->address + 4);
    	short* sp2 = (short*)(add2->address + 4);

	if (*sp1 != *sp2) return false;

    	return true;
}