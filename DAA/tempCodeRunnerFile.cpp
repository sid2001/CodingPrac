#include <iostream>
#include <vector>
using namespace std;

int memo(vector<int> &vec, vector<vector<int>> &tab, int i, int j)
{

  if (i == j)
    return 0;
  if (tab[i][j] != -1)
    return tab[i][j];
  tab[i][j] = INT_MAX;
  for (int k = i; k < j; k++)
  {
    tab[i][j] = min(tab[i][j], memo(vec, tab, i, k) + memo(vec, tab, k + 1, j) + vec[i - 1] * vec[k] * vec[j]);
  }
  return tab[i][j];
}

int solve(vector<int> &vec, vector<vector<int>> &tab, int len)
{

  return memo(vec, tab, 1, len - 1);
}

int main()
{

  int len;
  cin >> len;
  int l = len;
  vector<int> vec(len);
  int c = 0;
  while (len--)
  {
    cin >> vec[c++];
  }
  vector<vector<int>> tab(l, vector<int>(l, -1));
  cout << solve(vec, tab, l) << endl;
  return 1;
}