#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void solve() {
  int n;
  ll ans = 0;
  cin>>n;
  ll x;
  for(int i = 0;i<n-1;i++) {
    cin>>x;
    if(i<n-2) {
      ans += x;
    }else {
      ans = x - ans;
    }
  }
  cin>>x;
  cout<<x-ans<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}