#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll Bsearch(vector<ll> &vec, ll x) {
  ll low = 0;
  ll high = vec.size()-1;
  ll mid = (low+high)/2;
  while(low<high) {
    mid = (low+high)/2;
    if(vec[mid]<x){
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  //cout<<"\nmid: "<<mid<<"\n";
  return mid;
}

void solve() {
  ll n,m,q;
  cin>>n>>m>>q;
  vector<ll> vec(m);
  for(ll i = 0;i<m;i++) {
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end());
  for(ll i = 0; i < q; i++) {
    ll x;
    cin >>x;
    if(x<vec[0]) {
      cout<<vec[0]-1<<"\n";
      continue;
    }else if(x>vec[m-1]) {
      //cout<<"x: "<<x<<"n "<<vec[m-1]<<"\n";
      cout<<n-vec[m-1]<<"\n";
      continue;
    }
    ll idx = Bsearch(vec,x);
    if(x<vec[idx]) {
      idx--;
    }else if(x>vec[idx+1]){
      idx++;
    }
    ll a,b;
    a = vec[idx];
    if(vec.size()>1)
      b = vec[idx+1];
    cout<<(b-a)/2<<"\n";
  }
}

int main() {
  ll t;
  cin>>t;
  while(t--) {
    solve();
  }
}