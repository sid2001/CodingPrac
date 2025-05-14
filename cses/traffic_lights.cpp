#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

// int main()
// {
//   ll length, t_lights;
//   cin >> length >> t_lights;
//   set<ll> tl{0, length};
//   multiset<ll> diff{length};

//   for (ll i = 0; i < t_lights; i++)
//   {
//     ll x;
//     cin >> x;

//     auto it = tl.upper_bound(x);
//     auto it1 = it;
//     --it1;
//     diff.erase(diff.find(*it - *it1));
//     diff.insert(x - *it1);
//     diff.insert(*it - x);
//     tl.insert(x);
//     auto itt = diff.end();
//     --itt;
//     cout << *itt << endl;
//   }
// }

int main()
{
  ll length, t_lights;
  cin >> length >> t_lights;
  vector<ll> lights(t_lights);
  set<ll> tl{0, length};
  for (auto &i : lights)
  {
    cin >> i;
    tl.insert(i);
  }
  ll prev = 0;
  ll max_l = 0;
  for (auto &i : tl)
  {
    max_l = max(max_l, i - prev);
    prev = i;
  }
  vector<ll> diff(t_lights + 1);
  diff[t_lights] = max_l;
  ll c = t_lights;
  for (ll i = t_lights - 1; i >= 0; i--)
  {
    auto k1 = tl.upper_bound(lights[i]);
    auto k2 = k1;
    k2--;
    k2--;
    max_l = max(*k1 - *k2, max_l);
    tl.erase(--k1);
    diff[--c] = max_l;
  }
  int p = 1;
  for (auto &i : diff)
  {
    if (p == 1)
    {
      p++;
      continue;
    }
    cout << i << ' ';
  }
}