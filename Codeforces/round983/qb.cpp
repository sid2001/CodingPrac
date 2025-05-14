#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void solve() {
  ll n, k;
  cin>>n>>k;
  if(n==1&&k==1){
    cout<<1<<"\n";
    cout<<1<<"\n";
    return;
  }else if(n==1){
    cout<< -1<<"\n";
    return;
  }
  if(n==3){
    if(k==2){
      cout<<3<<"\n";
      cout<<1<<" "<<2<<" "<<3<<"\n";
    }else{
      cout<< -1<<"\n";
    }
    return;
  }
  ll l = k-1;
  ll r = n-k;
  if(k<n&&k>1){
    if(k%2==0){
      cout<<3<<"\n";
      cout<<1<<" "<<k<<" "<<k+1<<"\n";
    }else{
      cout<<3<<"\n";
      cout<<1<<" "<<k-1<<" "<<k+2<<"\n";
    }
  }else{
    cout<< -1<<"\n";
  }
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}