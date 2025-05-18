/* Output from p2c 1.21alpha-07.Dec.93, the Pascal-to-C translator */
/* From input file "program1.pas" */


#include <p2c/p2c.h>


#define max             500


typedef uchar hpn[max];

/* 1 = smallest */
/* 100 = biggest */


Static long gi, gj, gk;
Static hpn a[80][80];
Static boolean z[80][80];
Static hpn inp[10];
Static hpn b, c, d;
Static long gx, gy, gz, gw, gv;


Static Void zero(d)
uchar *d;
{
  long i;

  gw++;
  for (i = 0; i < max; i++)
    d[i] = 0;
}


Static Void dump(d)
uchar *d;
{
  long i;

  for (i = max - 1; i >= 0; i--)
    printf("%d", d[i]);
  putchar('\n');
}


Static uchar *plus(Result, a, b)
uchar *Result, *a, *b;
{
  long i, m;
  hpn tmp;

  gx++;
  zero(tmp);
  for (i = max; i >= 1; i--) {
    if (a[i-1] > 0 || b[i-1] > 0) {
      m = i;
/* p2c: program1.pas, line 30:
 * Warning: Expected a '(', found a semicolon [227] */
/* p2c: program1.pas, line 30:
 * Warning: Expected an expression, found a semicolon [227] */
      break;
    }
  }
  for (i = 0; i < m; i++) {
    tmp[i] += a[i] + b[i];
    tmp[i+1] = tmp[i] / 10;
    tmp[i] %= 10;
  }
  return memcpy(Result, tmp, sizeof(hpn));
}


Static uchar *i2h(Result, x, pow)
uchar *Result;
long x, pow;
{
  hpn t;
  long i;

  gy++;
  zero(t);
  i = pow;
  while (x > 0) {
    t[i-1] = x % 10;
/* p2c: program1.pas, line 47:
 * Note: Using % for possibly-negative arguments [317] */
    x /= 10;
    i++;
  }
  return memcpy(Result, t, sizeof(hpn));
}


Static uchar *mul(Result, a, x)
uchar *Result, *a;
long x;
{
  long i;
  hpn t, t2, t3;
  long m;

  gv++;
  zero(t);
  for (i = max; i >= 1; i--) {
    if (a[i-1] > 0) {
      m = i;
/* p2c: program1.pas, line 61:
 * Warning: Expected a '(', found a semicolon [227] */
/* p2c: program1.pas, line 61:
 * Warning: Expected an expression, found a semicolon [227] */
      break;
    }
  }
  for (i = 1; i <= m; i++) {
    i2h(t3, a[i-1] * x, i);
    plus(t2, t3, t);
    memcpy(t, t2, sizeof(hpn));
  }
  return memcpy(Result, t, sizeof(hpn));
}



Static uchar *func(Result, x, y)
uchar *Result;
long x, y;
{
  hpn t, t2, t3, TEMP;

  if (x == 0 || y == 0)
    return (i2h(Result, 1L, 1L));
  if (!z[x-1][y-1])
    return memcpy(Result, a[x-1][y-1], sizeof(hpn));
  gz++;
  /*t := func(x-1,y)*y + func(x,y-1)*x;*/

  func(t3, x - 1, y);
  mul(t, t3, y);
  func(t3, x, y - 1);
  mul(t2, t3, x);
  memcpy(t, plus(TEMP, t, t2), sizeof(hpn));

  memcpy(a[y-1][x-1], t, sizeof(hpn));
  z[y-1][x-1] = false;
  memcpy(a[x-1][y-1], t, sizeof(hpn));
  z[x-1][y-1] = false;
  return memcpy(Result, t, sizeof(hpn));
}


/*assume a*/


main(argc, argv)
int argc;
Char *argv[];
{
  for (gi = 1; gi <= 80; gi++) {
    for (gj = 1; gj <= 80; gj++) {
      zero(a[gi-1][gj-1]);
      z[gi-1][gj-1] = true;
    }
  }
  zero(b);
  func(b, 60L, 60L);
  dump(b);
  printf("%12ld %12ld %12ld\n", gx, gy, gz);
  printf("%12ld %12ld %12ld\n", gw, gv, gz);
  exit(EXIT_SUCCESS);
}




/* End. */
