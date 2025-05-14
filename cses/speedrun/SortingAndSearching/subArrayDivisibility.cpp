#include <iostream>
#include <vector>
#include <map>
#define ll long long 
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<ll> vec(n);
  map<ll, int> mp;
  ll ans = 0;
  for(int i = 0; i < n; i++) cin>> vec[i];
  mp.insert({0,1});
  ll ps = 0;
  for(int i = 0; i < n; i++) {
    ps += vec[i];
    ll rem = ps%n;
    rem = rem < 0 ? rem + n : rem;
    auto it = mp.find(rem);
    if(it != mp.end()) {
      ans += it->second;
    }
    if(it!=mp.end()) it->second++;
    else mp.insert({rem,1});
  }
  cout<<ans<<"\n";
  
  return 0;
}