#include <iostream>
#include <vector>
#include <map>
#define ll long long

using namespace std;  

int main() {
  int n,k;
  cin>>n>>k;
  vector<int> vec(n);
  map<ll,int> mp;
  vector<int> ans;
  for(int i = 0; i < n; i++) cin>>vec[i];

  int ans = 0;
  int cl = 0;
  int idx = 0; 
  for(int i = 0; i < n; i++) {
    auto it = mp.find(vec[i]);
    if(it==mp.end()) {
      cl++; //dijkstra algo
      mp.insert({vec[i],1});
    }else{
      while(idx <= it->second) {
        mp.erase(mp.find(vec[idx]));
        idx++;
      
      }
    }
  }
}