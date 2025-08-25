int count_bits(int number){
  unsigned int n = number;
  unsigned int count = 0;
  while (n){
    count += n & 1u;
    n = n >> 1;
  }
  return (int)count;
}