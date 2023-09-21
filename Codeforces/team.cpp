#include <bits\stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> v;
  for (int i = 0; i < n; ++i)
  {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back({a, b, c});
  }
  int c = 0;
  for (auto &i : v)
  {
    if (accumulate(i.begin(), i.end(), 0) >= 2)
    {
      ++c;
    }
    }
  cout << c << endl;
  return 0;
}