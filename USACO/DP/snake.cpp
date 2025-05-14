#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &vec, int k, int score)

int main() {
  int n,k;
  cin>>n>>k;

  vector<int> vec(n,0);
  vector<int> tab(n,0);
  for(int i = 0; i<n;i++){
    cin>>vec[i];
  }
  solve(vec, k);

  return 0;
} 