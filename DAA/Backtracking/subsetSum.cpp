#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void printSeq(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << ' ';
  }
  cout << endl;
  return;
}
void subsetSum(vector<int> &vec, int arr[], int curr, int &len, int target, int sum = 0)
{
  if (curr == len || sum >= target)
  {
    if (sum == target)
      printSeq(arr, len);
    return;
  }
  else
  {
    sum += vec[curr];
    arr[curr] = 1;
    subsetSum(vec, arr, curr + 1, len, target, sum);
    sum -= vec[curr];
    arr[curr] = 0;
    subsetSum(vec, arr, curr + 1, len, target, sum);
  }
}

int main()
{
  int t;
  cin >> t;
  int len = t;
  int i = 0;
  int arr[t];
  vector<int> vec;
  while (t--)
  {
    int x;
    cin >> x;
    arr[i++] = 0;
    vec.push_back(x);
  }
  int target;
  cin >> target;
  subsetSum(vec, arr, 0, len, target);

  return 1;
}