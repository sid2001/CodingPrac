#include <bits\stdc++.h>
using namespace std;
int main()
{
  int num;
  vector<string> v;
  cin >> num;
  for (int i = 0; i < num; i++)
  {
    string str;
    cin >> str;
    v.push_back(str);
  }
  for (auto &ele : v)
  {
    int len = ele.size();
    if (len > 10)
    {
      cout << ele[0] << len - 2 << ele[len - 1] << endl;
    }
    else
    {
      cout << ele << endl;
    }
  }
  return 0;
}
