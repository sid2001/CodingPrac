#include <set>
#include <iostream>
using namespace std;

int main()
{

  int n, a, b;
  cin >> n;
  multiset<pair<int, int>> time;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    time.insert({a, b});
  }
  int c = 0;
  int prev = 0;
  for (auto i = time.begin(); i != time.end(); i++)
  {
    if (i->first >= prev)
    {
      c++;
      prev = i->second;
    }
    else if (i->first < prev && i->second < prev)
    {
      prev = i->second;
    }
  }
  cout << c << endl;
}