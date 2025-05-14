#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main() {
  int n;
  ll m;
  cin>> n>>m;
  vector<ll> vec(n);
  map<ll, int> mp;
  for(int i = 0; i < n; i++) cin>>vec[i];
  ll ps = 0;
  ll ans = 0;
  mp.insert({0,1});
  for(int i = 0; i < n; i++) {
    ps += vec[i];
    
    if(mp.find(ps-m) != mp.end()) {
      ans += mp.find(ps-m)->second;
    }
    if(mp.find(ps)!=mp.end()) mp.find(ps)->second += 1;
    else mp.insert({ps,1});
  }
  cout<<ans<<"\n";
}