#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
  int t;
  cin >> t;
  ll x;
  vector<ll> vec;
  ll c = 0;

  for (int i = 0; i < t; i++)
  {
    cin >> x;
    auto lb = upper_bound(vec.begin(), vec.end(), x);
    if (lb != vec.end())
    {
      *lb = x;
    }
    else
    {
      vec.push_back(x);
      c++;
    }
  }
  cout << c << endl;
}