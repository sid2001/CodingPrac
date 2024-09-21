#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n,k;
  cin>>n>>k;
  int o = n/2;
  if(o*2!=n) o++;
  int e = n - o;
  int n_o = 0;
  int n_e = 0;
  if(n>k) {
    n_o = (n-k)/2;
    if(n_o*2!=(n-k)) n_o++;
    n_e = (n-k) - n_o;
  }
  o = o - n_o;
  e = e - n_e;
  if(o%2==0) cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";

  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}