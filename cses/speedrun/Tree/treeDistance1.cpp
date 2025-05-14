#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &vec, vector<int> &ans, int curr, int p,int dist = 0) {
  
  int dep = 0;
  for(auto v : vec[curr]) {
    if(v != p || curr == p){
      dep = max(dep, 1 + solve(vec,ans,v,curr,dist+1));
    }
  }
  ans[curr] = max(dist,dep);
  return dep;
}

int main() {
  int n,a,b;
  cin>>n;
  vector<vector<int>> vec(n);
  vector<int> ans(n);
  for(int i = 0; i < n-1; i++) {
    cin>>a>>b;
    vec[a-1].push_back(b-1);
    vec[b-1].push_back(a-1);
  }
  for(int i = 0; i < n; i++){
    if(vec[i].size()==1) {
      solve(vec,ans,i,i);
      break;
    }
  }
  for(int i = 0; i < n; i++) cout<<ans[i]<<" ";
}