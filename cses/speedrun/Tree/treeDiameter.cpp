#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<vector<int>> &vec,int &dist ,int curr = 0, int p = 0){

  int d1 = 0, d2 = 0;
  // cout<<"visiting: "<<curr<<"\n";
  for(auto v : vec[curr]){
    if(v != p || curr==p){
      int depth = 1 + solve(vec,dist, v, curr);
      d2 = max(d2, min(depth,d1));
      d1 = max(d1, depth);
    }
  }
  dist = max(dist, d1 + d2);
  return d1;
}

int main() {
  int n,a,b;
  cin>>n;
  int ans = 0;
  vector<vector<int>> vec(n);
  for(int i = 0; i < n-1; i++) {
    cin>>a>>b;
    vec[a-1].push_back(b-1);
    vec[b-1].push_back(a-1);
  }
  solve(vec,ans);
  cout << ans;
}