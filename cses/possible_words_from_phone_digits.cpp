#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> vec = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<int> ve = {3, 3, 3, 3, 3, 4, 3, 4};

void combi(int indx, int arr[], vector<string> &vc, string st, int n, int N)
{
  // cout << indx << " " << arr[indx] << " " << st << " " << n << endl;
  for (int i = 0; i < ve[arr[indx] - 2]; i++)
  {
    if (n == 0)
    {
      vc.push_back(st);
      return;
    }
    string s = st;
    st += vec[arr[indx] - 2][i];
    if (indx + 1 == N)
    {
      combi(indx, arr, vc, st, n - 1, N);
    }
    else
      combi(indx + 1, arr, vc, st, n - 1, N);
    st = s;
  }
  return;
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  string st = "";
  vector<string> vc;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  combi(0, arr, vc, st, n, n);
  for (auto &i : vc)
  {
    cout << i << endl;
  }
  cout << vc.size();
}