void decode1(long *xp, long *yp, long *zp) {
  long x = *xp;
  long y = *yp;
  long z = *zp;

  *yp = x;
  *zp = y;
  *xp = z;

}

long scale2(long x, long y, long z) {
  long t = 5*x + 2*y + 8*z;
  return t;
}

long arith2(long x, long y, long z) {
  long t1 = x | y;
  long t2 = t1 >> 3;
  long t3 = ~t2;
  long t4 = z - t3;
  return t4;
}

int main()
{
  return 0;
}
