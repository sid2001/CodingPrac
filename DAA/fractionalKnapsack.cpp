#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<float, float>> vec(n, make_pair(0, 0));

  for (int i = 0; i < n; i++)
  {

    cin >> vec[i].second;
  }
  for (int i = 0; i < n; i++)
  {

    cin >> vec[i].first;
    vec[i].first = -1 * vec[i].first / vec[i].second;
  }
  sort(vec.begin(), vec.end());

  double capacity;
  cin >> capacity;
  double sum = 0;

  for (auto i : vec)
  {

    if (i.second <= capacity)
    {
      sum += -1 * i.first * i.second;
      capacity -= i.second;
    }
    else
    {
      sum += -1 * i.first * capacity;
      capacity = 0;
      break;
    }
  }
  cout << sum << endl;
}