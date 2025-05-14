// #include <bits\stdc++.h>
// using namespace std;

// int main()
// {
//   multiset<int> cus;
//   multiset<int> tic;
//   int ticnum, cusnum;
//   string st_tic, st_cus;
//   cin >> ticnum >> cusnum;
//   getline(cin, st_tic);
//   getline(cin, st_cus);
//   for (auto i : st_tic)
//   {
//     tic.insert(int(i));
//   }
//   for (auto j : st_cus)
//   {
//     cus.insert(int(j));
//   }
//   int c = 0;
//   auto i = --cus.end();
//   auto j = --tic.end();
//   while (true)
//   {
//     if (*j <= *i)
//     {
//       c++;
//       if (j == tic.begin() || i == cus.begin())
//       {
//         cout << c;
//         return 0;
//       }
//       --j;
//       --i;
//     }
//     else
//     {
//       if (j == tic.begin())
//       {
//         cout << c;
//         return 0;
//       }
//       --j;
//     }
//   }
//   return 0;
// }

#include <set>
#include <iostream>
using namespace std;

int main()
{
  int customer_count, ticket_count;
  cin >> ticket_count >> customer_count;
  multiset<int> customer_prices, ticket_prices;
  int cp, tp;
  for (int i = 0; i < ticket_count; i++)
  {
    cin >> tp;
    ticket_prices.insert(-tp);
  }
  for (int i = 0; i < customer_count; i++)
  {
    cin >> cp;
    customer_prices.insert(-cp);
    auto it = ticket_prices.lower_bound(-cp);
    cout << (it != ticket_prices.end() ? -(*it) : -1) << endl;
    if (it != ticket_prices.end())
      ticket_prices.erase(it);
  }
}