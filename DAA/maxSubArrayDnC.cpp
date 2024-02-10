#include <bits/stdc++.h>

using namespace std;

int CSS(int negInf, int vec[], int low, int high, int mid)
{

  int s = 0;
  int left = negInf;

  for (int i = mid; i >= low; i--)
  {
    s += vec[i];
    if (s > left)
      left = s;
  }

  s = 0;
  int right = negInf;

  for (int i = mid; i <= high; i++)
  {
    s += vec[i];
    if (s > right)
      right = s;
  }

  return max(left + right - vec[mid], max(right, left));
}

int MSA(int negInf, int vec[], int low, int high)
{

  if (low == high)
    return vec[low];

  else
  {
    int mid = (low + high) / 2;
    int left = MSA(negInf, vec, low, mid);
    int right = MSA(negInf, vec, mid + 1, high);
    int cross = CSS(negInf, vec, low, high, mid);

    return max(left, max(right, cross));
  }
}

int main()
{

  int size;
  int negInf = 0;

  cin >> size;

  int vec[size];
  int high = size - 1;
  int i = 0;

  while (size--)
  {
    int x;
    cin >> x;
    vec[i++] = x;
    if (negInf > x)
      negInf = x;
  }

  --negInf;
  cout << MSA(negInf, vec, 0, high) << endl;

  return 0;
}