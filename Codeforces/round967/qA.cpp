#include<iostream>
#include<vector>
#include <algorithm>
#include <utility>
using namespace std;


void solve() {
  int n;
  cin>>n;
  vector<int> vec(n,0);
  vector<int> hmap(101,0);
  for(int i = 0; i < n; i++) {
    cin>>vec[i];
    hmap[vec[i]]++;
  }
  sort(hmap.begin(),hmap.end());
  int i = hmap.size()-1;
  //for(int i = hmap.size(); i > 0; i--) {
    while(hmap[i]==0) {
      i--;
    }
    int curr = hmap[i];
  //}
  cout<<vec.size() - curr<<"\n";
}
int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}