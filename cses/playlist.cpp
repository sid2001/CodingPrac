#include <iostream>
#include <unordered_map>
#include <algorithm>
using ll = long long;
using namespace std;
int main()
{
  ll n;
  cin >> n;
  unordered_map<ll, ll> lastindex;
  ll x;
  ll ma = 0;
  ll curr = 0;
  ll min_i = 0;

  for (ll i = 0; i < n; i++)
  {
    cin >> x;
    auto c = lastindex.find(x);
    if (c != lastindex.end())
    {
      if (min_i <= c->second)
      {
        min_i = c->second + 1;
        curr = i - min_i;
      }
      c->second = i;
    }
    else
    {
      lastindex.insert({x, i});
    }
    curr++;
    ma = max(ma, curr);
  }
  cout << ma << endl;
}