
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for ( i = 0; i < len; i++)
  {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void inplace_swap(int *x, int *y) {
   *y = *x ^ *y;
   *x = *x ^ *y;
   *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {

  for (int first = 0, last = cnt-1; first < last; first++, last--)
  {
    inplace_swap(&a[first], &a[last]);
  }

  for (int i = 0; i < cnt; i++)
  {
    printf("%d", a[i]);
  }
  
}

int bis(int x, int m) {
  return x|m;
}

int bic(int x, int m) {
  return x&(~m);
}

int bool_or(int x, int y) {
  int rs = bis(x,y);
  return rs;
}

int bool_xor(int x, int y) {
  int rs = bis(bic(x,y), bic(y,x));
  return rs;
}

int func1(unsigned word) {
  return (int32_t) ((word << 24) >> 24);
}

int func2(unsigned word) {
  return ((int32_t) word << 24) >> 24;
}

int strlonger(char *s, char *t) {
  printf("s len is %d\n", strlen(s));
  printf("t len is %d\n", strlen(t));

  unsigned slen = strlen(s);
  unsigned tlen = strlen(t);

  printf("minus result is %d\n", slen - tlen);

  return slen - tlen > 0;
}

float sum_element(float a[], unsigned len) {
  int i;
  float rs = 0;

  for (i = 0; i <= len - 1; i++)
  {
    printf("i is %d\n", i);
    rs += a[i];
  }
  
  return rs;
}

int div16(int32_t x) {
  int bias = x >> 31 & 0xf;
  return x + bias >> 4;
}

int show_short(short s) {
  show_bytes((byte_pointer) &s, sizeof(short));
}

int show_long(long l) {
  show_bytes((byte_pointer) &l, sizeof(long));
}

int is_little_endian () {
  short i = 1;

  byte_pointer b = (byte_pointer) &i;

  int rs = b[0] == 0x00 ? 0 : 1;

  printf("%.2x", b[0]);

  printf("%d", rs);
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
  return (x & ~(0xFF<<(i*8))) | (b << (i*8));
}

int int_shift_are_artimetic() {
  int y = !!(~0 >> 63);

  printf("%d", y);
}

int srl(unsigned x, int k) {
  unsigned xsra = (int) x >> k;

  int w = 8 * sizeof(xsra);

  unsigned z = 2 << (w - 1 - k );

  return (z -1) & xsra;
}

int any_odd_one(unsigned x) {
  return !!(x & 0x55555555);
}

int lower_one_mask(int n) {
  int w = sizeof(n) >> 3;

  return (unsigned) -1 >> (w - n);
}

int odd_ones(unsigned x) {
  x ^= x >> 1;
  x ^= x >> 2;
  x ^= x >> 4;
  x ^= x >> 8;
  x ^= x >> 16;

  return x & 1;
}

int leftmost_one(unsigned x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;

  return x & (~x >> 1);
}

int bad_int_size_is_32() {
  int set_msb = 1 << 15 << 15 <<1;
  int beyond_msb = set_msb << 1; 

  return set_msb && !beyond_msb;
}

unsigned rotate_left(unsigned x, int n) {
  int w = sizeof(x) << 3;

  return  x >> (w - 1 - n) >> 1 | x << n;
}

int fits_bits(int x, int n) {
  x >>= n - 1;

  return !(x >> 1) || !~x;
}

int saturationg_add(int x, int y) {
  int sum = x + y;
  int sig_mask = INT_MIN;

  int pos = !(x & sig_mask) && !(y & sig_mask) && (sum & sig_mask);
  int neg = (x & sig_mask) && (y && sig_mask) && !(sum & sig_mask);

  (pos && (sum = INT_MAX)) ||  (neg && (sum = INT_MIN));

  return sum;
}

int tsub_ok(int x, int y) {
  if (y == INT_MIN)
  {
    return 0;
  }

  int neg_y = -y;
  int sum = x + neg_y;

  int pos_over = x > 0 && neg_y > 0 && sum < 0;
  int neg_over = x < 0 && neg_y < 0 && sum >= 0;

  return !(pos_over || neg_over);
}

int main()
{
  assert(lower_one_mask(6) != 0x3f);
}
