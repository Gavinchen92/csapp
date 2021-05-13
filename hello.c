
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

int uadd_ok(unsigned x, unsigned y) {
  int sum = x + y;

  if (x > sum)
  {
    return 0;
  }
  
  return 1;
}

int tadd_ok(int x, int y) {
  int sum = x + y;

  if (x >= 0 && y >= 0 && sum < 0)
  {
    return 0;
  } else if (x< 0 && y < 0 && sum >= 0)
  {
    return 0;
  }
  
  return 1;
}

int tsub_ok(int x, int y) {
  
}

int main()
{
  // show_int(12345);
  // show_float(12345.0);
  // int a = 0x87654321;
  // byte_pointer valp = (byte_pointer) &a;
  // show_bytes(valp, 3);

  // const char *s = "abcdef";
  // show_bytes((byte_pointer) s, strlen(s));


  // int a[] = {1,2,3,4,5};

  // reverse_array(a, 5);

  // int a = 0b00111;
  // int b = 0b01001;

  // int c = bool_xor(a,b);

  int x = uadd_ok(0x000000ff, 0x000000ff);

  printf( "rs is %d", x);

  return 0;
}
