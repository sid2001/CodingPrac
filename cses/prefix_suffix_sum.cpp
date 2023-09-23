#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string revers(string str)
{
  string str1 = "";
  for (int i = str.length() - 1; i >= 0; i--)
    str1 += str[i];
  return str1;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int nele;
    string x;
    vector<string> vec;
    for (int j = 0; j < nele; j++)
    {
      cin >> x;
      if (find(vec.begin(), vec.end(), x) != vec.end())
      {
        vec.pop_back(*find(vec.begin(), vec.end(), x));
      }
      else
        vec.push_back(revers(x));
    }
    if (vec.empty())
    {
      cout << "YES" << endl;
    }
    else
      cout << "NO" << endl;
  }
}

// void swap(int &a, int &b)
// {
//   int temp = a;
//   a = b;
//   b = temp;
//   cout << &a << " " << &b << " " << endl;
//   return;
// }
// int main()
// {
//   int a = 2;
//   int b = 3;
//   swap(a, b);
//   cout << a << " " << b << endl;
//   cout << &a << " " << &b << endl;
//   return 0;
// }