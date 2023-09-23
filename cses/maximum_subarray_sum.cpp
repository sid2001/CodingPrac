#include <vector>
#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> vec(n);
  long long x;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    if (i != 0)
      vec[i] = vec[i - 1] + x;
    else
      vec[i] = x;
  }
  long long max_sum = vec[0];
  long long min_ele = 0;
  for (int i = 0; i < n; i++)
  {
    max_sum = max(max_sum, vec[i] - min_ele);
    min_ele = min(vec[i], min_ele);
  }
  cout << max_sum << endl;
}