#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n,k,x;
  cin>>n>>x>>k;
  int xx = min(x,k);
  int ans = n/xx;
  if(n%xx) ans++;
  cout<<ans<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}