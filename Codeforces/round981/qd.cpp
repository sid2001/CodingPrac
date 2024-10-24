#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve(){ 
  int n;
  cin>>n;
  vector<int> vec(n,0);
  for(int i = 0; i<n;i++){
    cin>>vec[i];
    if(i != 0){
      vec[i] += vec[i-1];
    }
  }
  int ans = 0;
  map<int, vector<int>> mp;
  for(int i = 0; i<n; i++) {
    if(mp.find(vec[i]) == mp.end()) {
      mp.insert({vec[i], {1}});
      mp[vec[i]].push_back(i);
    }else{
      mp[vec[i]].push_back(i);
    }
  }
  int ll = -1;
  if(vec[0]==0){
    ans++;
    ll = 0;
  }
  for(int i = 1 ; i < n; i++) {
    if(mp.find(vec[i]) != mp.end()) {
      int idx = mp[vec[i]][0];
      while(idx < mp[vec[i]].size() && mp[vec[i]][idx] < ll){
        mp[vec[i]][idx]++;
        idx++;
      }
      if(mp[vec[i]].size() > idx && mp[vec[i]][idx] < i){
        ans++;
        mp[vec[i]][0]++;
        ll = i;
      }
    }
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

