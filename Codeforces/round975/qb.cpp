#include <iostream>
#include <vector> 
#include <unordered_map>
#define ull unsigned long long

using namespace std;

void solve() {
  ull n,q;
  cin>>n>>q;
  vector<ull> vec(n);
  unordered_map<ull,ull> mp;
  ull points = 0;
  for(int i = 0;i<n;i++) {
    cin>>vec[i];
    if(i>0) {
      points = vec[i] - vec[i-1] - 1;
      ull seg = n-1;
      seg += (n-1-i)*(i-1);
      if(mp.find(seg)==mp.end()) {
        mp[seg] = points;
      }else {
        mp[seg]+= points;
      }
    }
  }
  for(int i = 0;i<n;i++) {
    ull segs = n - 1;
    segs += (n-1-i)*i;
    if(mp.find(segs)==mp.end()) {
      mp[segs] = 1;
    }else {
      mp[segs]++;
    }
  }
  for(int i = 0;i<q;i++) {
    ull x;
    cin>>x;
    if(mp.find(x)==mp.end()) {
      cout<<0<<" ";
    }else {
      cout<<mp[x]<<" ";
    }
  }
  cout<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--){ 
    solve();
  }
}
