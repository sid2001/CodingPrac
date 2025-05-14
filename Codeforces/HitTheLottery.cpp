#include <bits\stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int c = 0;
  int arr[5] = {100, 20, 10, 5, 1};
  int p = 0;
  while (n > 0)
  {
    if (n / arr[p] != 0)
    {
      c += n / arr[p];
      n -= (n / arr[p]) * arr[p];
    }
    else
    {
      ++p;
    }
  }
  cout << c << endl;
}