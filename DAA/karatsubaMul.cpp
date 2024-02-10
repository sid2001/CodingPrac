// formula k(x,y) = k(a,c)*10^n/2 + [k(a+b,c+d) - k(a,c) - k(b,d)]*10^n/2 + k(b,d)
// x=(a|b) y=(c|d)

#include <bits/stdc++.h>
using namespace std;

long findLength(long a, long b)
{
  long count = 0;
  while (a > 0 && b > 0)
  {
    count++;
    a /= 10;
    b /= 10;
  }
  return count;
}

long karatsuba(long a, long b, long len)
{

  if (len <= 1)
  {
    return a * b;
  }
  long x = len / 2;
  long y = (long)pow(10, x);
  long a0 = a % y;
  long a1 = a / y;
  long b0 = b % y;
  long b1 = b / y;

  long z2 = karatsuba(a1, b1, x);
  long z0 = karatsuba(a0, b0, x);
  long z1 = karatsuba(a1 + a0, b0 + b1, x) - z2 - z0;
  return z2 * y * y + z1 * y + z0;
}

int main()
{
  long a, b;
  cin >> a >> b;
  long len = findLength(a, b);
  cout << karatsuba(a, b, len) << endl;

  return 1;
}
