#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int comperator1(vector<int> a, vector<int> b) {
  if(a[0] > b[0]) {
    return 1;
  }
  return 0;
}
int comperator2(vector<int> a, vector<int> b) {
  if(a[1] > b[1]) {
    return 1;
  }
  return 0;
}
void solve() {
  int n;
  cin>>n;
  vector<vector<int>> vec1(n,vector<int>(2,0));
  vector<vector<int>> vec2(n,vector<int>(2,0));
  for(int i = 0; i < n; i++) {
    cin>>vec1[i][0]>>vec1[i][1];
    vec2[i][0] = vec1[i][0];
    vec2[i][1] = vec1[i][1];
  }
  sort(vec1.begin(),vec1.end(),comperator1);
  sort(vec2.begin(),vec2.end(),comperator2);

  
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}