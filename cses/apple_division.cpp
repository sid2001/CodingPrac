#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;

ll min_sum(vector<ll> &vec, int indx, ll curr_sum, ll sum, map<pair<int, ll>, ll> &mp, int size)
{
  if (indx == size)
  {
    return abs(sum - 2 * curr_sum);
  }
  if (mp.find({indx, curr_sum}) != mp.end())
  {
    return mp[{indx, curr_sum}];
  }
  ll a = min_sum(vec, indx + 1, curr_sum + vec[indx], sum, mp, size);
  ll b = min_sum(vec, indx + 1, curr_sum, sum, mp, size);
  mp[{indx, curr_sum}] = min(a, b);
  return mp[{indx, curr_sum}];
}

int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  ll sum = 0;
  map<pair<int, ll>, ll> mp;
  for (auto &i : vec)
  {
    cin >> i;
    sum += i;
  }
  cout << min_sum(vec, 0, 0, sum, mp, vec.size()) << endl;
}