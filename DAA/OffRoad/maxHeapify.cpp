// T(n) = O(nlogn)
#include <bits/stdc++.h>
#include "myFunctions.h"

using namespace std;

void exchange(vector<int> &vec, int i1, int i2)
{
  i1--;
  i2--;
  vec[i1] = vec[i1] + vec[i2];
  vec[i2] = vec[i1] - vec[i2];
  vec[i1] = vec[i1] - vec[i2];
  return;
}

void maxHeapify(vector<int> &vec, int i, int size)
{
  int left = 2 * i;
  int right = 2 * i + 1;
  int largest;
  if (left <= size && vec[left - 1] > vec[i - 1])
  {
    largest = left;
  }
  else
    largest = i;
  if (right <= size && vec[right - 1] > vec[largest - 1])
    largest = right;
  if (largest != i)
  {
    exchange(vec, i, largest);
    maxHeapify(vec, largest, size);
  }
  return;
}

void buildMaxHeap(vector<int> &vec, int size)
{
  int n = size / 2;
  for (int i = n; i > 0; i--)
  {
    maxHeapify(vec, i, size);
  }
  return;
}

void print(vector<int> &vec)
{
  for (auto i : vec)
  {
    cout << i << ' ';
  }
  cout << endl;
  return;
}

// int main()
// {
//   int size;
//   cin >> size;

//   vector<int> vec(size);
//   for (int i; i < size; i++)
//   {
//     cin >> vec[i];
//   }
//   print(vec);
//   buildMaxHeap(vec, size);
//   print(vec);
// }