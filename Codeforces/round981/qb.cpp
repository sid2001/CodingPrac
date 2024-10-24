#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void solve() {
  int n;
  cin>>n;
  vector<vector<int>> vec(n, vector<int>(n));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin>>vec[i][j];
    }
  }
  int ans = 0;
  for(int j = 0; j < n; j++) {
    int i = 0;
    int k = 0;
    int m = 0;
    while(j + k < n && i + k< n) {
      m = min(vec[i+k][j+k], m);
      k++;
    }
    ans = ans + (m<0? -1*m : 0);
  }
  for(int i = 1; i < n; i++) {
    int j = 0;
    int k = 0;
    int m = 0;
    while(i + k<n && j +k < n) {
      m = min(vec[i+k][j+k], m);
      k++;
    }
    ans = ans + (m<0? -1*m : 0);
  }
  cout<<ans<<"\n";
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }

  return 0;
}