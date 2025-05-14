#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
  int n, k;
  cin>>n>>k;
  int b,c;
  vector<int> brands(k+1,0);
  for(int i = 0; i < k; i++) {
    cin>>b>>c;
    brands[b] += c;
  }
  sort(brands.begin(),brands.end(),greater<int>());
  int ans = 0;
  int idx = 0;
  while(n--) {
    if(brands[idx]==0) break;
    ans += brands[idx++];
  }
  cout<<ans<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}