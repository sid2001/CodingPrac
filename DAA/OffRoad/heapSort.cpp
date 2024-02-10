#include "myFunctions.h"
#include <bits/stdc++.h>

using namespace std;

void heapSort(vector<int> &vec, int size)
{
  int s = size;
  buildMaxHeap(vec, size);
  for (int i = s; i >= 2; i--)
  {
    exchange(vec, 1, i);
    size--;
    maxHeapify(vec, 1, size);
    print(vec);
  }
  return;
}

int main()
{
  int size;
  cin >> size;
  vector<int> vec(size);
  for (int i; i < size; i++)
  {
    cin >> vec[i];
  }
  print(vec);
  heapSort(vec, size);
  print(vec);
}