#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int max = 0;
  int min;
  int x;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    if (i == 0)
      min = x;
    if (min > x)
      min = x;
    if (max < x)
      max = x;
  }
  cout << max - min << endl;
}