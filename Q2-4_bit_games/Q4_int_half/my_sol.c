void int_half(int number, int * lower_half, int * upper_half){
  unsigned int n = (unsigned int)number;
  *lower_half = n & 0xFFFF;
  *upper_half = (n >> 16) & 0xFFFF;
}
