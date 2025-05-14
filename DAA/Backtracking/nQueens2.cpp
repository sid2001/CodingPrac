#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<int> &queens, int len)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len; j++)
    {
      if (queens[i] == j)
        cout << "Q";
      else
        cout << "-";
    }
    cout << endl;
  }
  cout << "**********" << endl;
  return;
}

int verifySpace(vector<int> &queens, int x, int y)
{
  for (int i = 0; i <= x; i++)
  {
    if (abs(x - i) == abs(y - queens[i]))
      return 0;
  }
  return 1;
}

void nQueen(vector<int> &queens, vector<int> &cols, int len, int curr, int marked = 0)
{
  if (marked == len)
  {
    printBoard(queens, len);
    return;
  }
  for (int i = 0; i < len; i++)
  {
    if (cols[i] == -1 && verifySpace(queens, curr, i) == 1)
    {
      queens[curr] = i;
      cols[i] = 1;
      marked++;
      nQueen(queens, cols, len, curr + 1, marked);
      marked--;
      queens[curr] = -1;
      cols[i] = -1;
    }
  }
  if (marked != curr + 1)
    return;
}

int main()
{
  int n;
  cin >> n;
  vector<int> queens(n, -1);
  vector<int> cols(n, -1);
  nQueen(queens, cols, n, 0);
}