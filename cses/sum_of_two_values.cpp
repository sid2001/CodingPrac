#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerbound(vector<pair<int, int>> &vec, int ts, int size)
{
  int lower = 0;
  int upper = size;
  int mid = (lower + upper) / 2;
  while (lower < upper)
  {
    mid = lower + (upper - lower) / 2;
    if (ts > vec[mid].first)
    {
      lower = mid + 1;
    }
    else if (ts <= vec[mid].first)
    {
      upper = mid;
    }
  }
  if (lower < size && vec[lower].first < ts)
  {
    lower++;
  }
  return lower;
}

int main()
{
  int size, ts;
  cin >> size >> ts;
  vector<pair<int, int>> vec;
  for (int i = 0; i < size; i++)
  {
    int a;
    cin >> a;
    vec.push_back({a, i + 1});
  }
  sort(vec.begin(), vec.end());
  auto b = lowerbound(vec, ts, size);
  int lower = 0, upper = --b;
  int l, u;
  while (lower < upper)
  {
    l = vec[lower].first;
    u = vec[upper].first;
    if (l + u == ts)
    {
      cout << vec[lower].second << " " << vec[upper].second << endl;
      return 0;
    }
    else if (l + u > ts)
    {
      --upper;
    }
    else
      ++lower;
  }
  cout << "IMPOSSIBLE" << endl;
}