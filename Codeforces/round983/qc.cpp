#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;



void solve() {
  int n;
  ll a;
  cin>>n;
  vector<ll> vec;
  for(int i = 0; i < n; i++) {
    cin>>a;
    vec.push_back(a);
  }
  sort(vec.begin(),vec.end());
  int i = 0;
  int j = n-1;
  int ans = 0;
  while(j > i) {
    if(vec[i] + vec[i+1] <= vec[n-1]){
      while(vec[j] + vec[i+1] > vec[n-1]) {
        j--;
      }
      j++;
      // cout<<"j : "<<j<<" i : "<<i<<"\n";
      ans++;
      i++;
    }else{
      break;
    }
  }
  int ans1 = 0;
  j = n-1;
  i=0;
  while(j > i) {
    if(vec[i] + vec[i+1] <= vec[j]){
      j--;
      ans1++;
    }else{
      break;
    }
  }
  cout<<min(ans,ans1)<<"\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}