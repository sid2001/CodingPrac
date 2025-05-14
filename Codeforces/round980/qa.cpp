#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

void solve() {
  ll n,k;
  cin>>n>>k;
  ll ans;
  if(n>=k){
    ans = n;
  }else if(2*n <= k){
    ans = 0;
  } else {
    ans = n - (k-n);
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