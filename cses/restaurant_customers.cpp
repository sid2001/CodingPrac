#include <iostream>
#include <set>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int max = 0;
  int c = 0;
  multiset<pair<int, int>> time;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    time.insert({a, 1});
    time.insert({b, -1});
  }
  for (auto i = time.begin(); i != time.end(); ++i)
  {
    c += i->second;
    if (c > max)
      max = c;
  }
  cout << max;
}