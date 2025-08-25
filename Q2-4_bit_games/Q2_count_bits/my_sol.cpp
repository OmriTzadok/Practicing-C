int count_bits(int number){
  int count = 0;
  while (number != 0){
    if ((number & 0x01) != 0) count++;
    number = number >> 1;
  }
  return count;
}