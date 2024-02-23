#include <bits/stdc++.h>

using namespace std;

void computePI(string &pattern)
{
  int m = pattern.length();
  int k = 0;
  int vec[m];
  vec[0] = 0;
  for (int i = 1; i < m; i++)
  {
    while (k > 0 && pattern[i] != pattern[k])
    {
      k = vec[k - 1];
    }
    if (pattern[k] == pattern[i])
      k++;
    vec[i] = k;
  }
  for (auto i : vec)
  {
    cout << i << " ";
  }
  // return vec;
}

int main()
{
  string pattern;
  cin >> pattern;
  computePI(pattern);
  // for (auto j : computePI(pattern))
  // {
  //   cout << j << " ";
  // }
  return 0;
}