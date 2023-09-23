#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

// int main()
// {
//   int n;
//   cin >> n;
//   vector<double> vec(n);
//   double x;
//   double sum = 0;
//   for (int i = 0; i < n; i++)
//   {
//     cin >> x;
//     vec[i] = x;
//     sum += x;
//   }
//   double mean = (sum / n);
//   sum = 0;
//   for (auto i : vec)
//   {
//     sum += max(i, mean) - min(i, mean);
//   }
//   cout << lround(sum);
// }
int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  for (ll &i : vec)
  {
    cin >> i;
  }
  sort(vec.begin(), vec.end());
  ll mid = vec[n / 2], ans = 0;
  for (ll &i : vec)
  {
    ans += abs(mid - i);
  }
  cout << ans;
}