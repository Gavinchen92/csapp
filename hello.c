
#include <stdio.h>
#include <string.h>

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

int main()
{
  unsigned x = replace_byte(0x12345678, 2, 0xab);

  printf("%x", x);
}
