#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<ll> vec(n);
  vector<int> ans(n,0);
  for(int i = 0; i < n; i++) {
    cin>>vec[i];
    int idx = i;
    while(idx>0) {
      if(vec[idx-1]<vec[i]) {ans[i] = idx;break;}
      else if(ans[idx-1]==0) {
        ans[i] = 0;
        break;
      }else{
        idx = ans[idx-1];
      }
    }
  }
  for(auto v : ans) {
    cout<<v<<" ";
  }
  return 0;
}