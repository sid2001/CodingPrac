#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
  int n;
  ll x;
  cin>>n>>x;
  vector<ll> vec(n);
  for(int i = 0 ; i < n; i++) {
    cin>>vec[i];
  }
  int ans = 0;
  ll csum = vec[0];
  int l = 0;
  if(csum == x) ans++;
  for(int i = 1; i < n; i++) {
    csum += vec[i];
    while(csum > x) {
      csum -= vec[l];
      l++;
    }
    if(csum == x) ans++;
  }
  cout<<ans<<"\n";
}