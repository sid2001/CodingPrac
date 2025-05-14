#include <vector>
#include <iostream>

using namespace std;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int marked = 0;

void printChessBoard(vector<int> &queens, int len)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len; j++)
    {
      cout << (queens[i] == j ? 'Q' : '*');
    }
    cout << endl;
  }
  cout << "------------------" << endl;
}
void markDiagonals(int x, int y, vector<int> &diagonals, int len, int type)
{
  // int mi = min(x, y);
  // for (int i = 0; i < 4; i++)
  // {
  //   int cx = x + dx[i] * mi;
  //   int cy = y + dy[i] * mi;
  //   if (cy >= cx)
  //   {
  //     diagonals[cx + cy] = (diagonals[cx + cy] + 1) % 2;
  //   }
  //   else if (cy < cx)
  //   {
  //     diagonals[cx + cy + (2 * len - 2)] = (diagonals[cx + cy + (2 * len - 2)] + 1) % 2;
  //   }
  // }
  float c1 = -(y + 0.5) - (x + 0.5);
  float c2 = -(y + 0.5) + (x + 0.5);
  // y=0
  if ((-1 - c1) > 0 && (-1 - c1) < len)
  {
    diagonals[-1 - c1 + (2 * len - 2)] = (diagonals[-1 - c1 + (2 * len - 2)] + 1) % 2;
  }
  if (c2 > 0 && c2 < len)
  {
    diagonals[c2 + (2 * len - 2)] = (diagonals[c2 + (2 * len - 2)] + 1) % 2;
  }
  // y=len-1
  if ((-len - c1) > 0 && (-len - c1) < len)
  {
    diagonals[-len - c1] = (diagonals[-1 - c1 + (2 * len - 2)] + 1) % 2;
  }
  if (c2 > 0 && c2 < len)
  {
    diagonals[c2 + (2 * len - 2)] = (diagonals[c2 + (2 * len - 2)] + 1) % 2;
  }
  return;
}
auto unmarkDiagonals = &markDiagonals;

bool validSpace(int x, int y, vector<int> &diagonals, vector<int> &col, int len)
{
  int mi = min(x, y);
  if (col[y] == 1)
    return false;
  for (int i = 0; i < 4; i++)
  {
    int cx = x + dx[i] * mi;
    int cy = y + dy[i] * mi;
    if ((cy >= cx && diagonals[cx + cy] == 1) || (cy < cx && diagonals[cx + cy + (2 * len - 2)]))
    {
      return false;
    }
  }
  return true;
}

void nQueen(vector<int> &queens, vector<int> columns, vector<int> &diagonals, int len, int curr = 0, int col = 0, bool flag = false)
{
  cout << "row: " << curr << "col: " << col << endl;
  cout << validSpace(curr, col, diagonals, columns, len) << endl;
  printChessBoard(queens, len);
  if (flag && (marked < curr + 1 || !validSpace(curr, col, diagonals, columns, len)))
  {
    cout << "not valid" << endl;
    // printChessBoard(queens, len);
    return;
  }
  else if (marked == len)
  {
    printChessBoard(queens, len);
    return;
  }
  else
  {
    for (int i = 0; i < len; i++)
    {
      flag = true;
      if (columns[i] != 1)
      {
        columns[i] = 1;
        markDiagonals(curr, i, diagonals, len);
        queens[curr] = i;
        marked++;
        nQueen(queens, columns, diagonals, len, curr + 1, i, true);
        markDiagonals(curr, i, diagonals, len);
        columns[i] = 0;
        queens[curr] = -1;
        marked--;
      }
    }
    nQueen(queens, columns, diagonals, len, curr + 1, 0, true);
  }
}

int main()
{

  int n;
  cin >> n;
  vector<int> queens(n, -1);
  vector<int> columns(n, 0);
  vector<int> diagonals(4 * n - 2, 0);
  nQueen(queens, columns, diagonals, n);
  return 1;
}