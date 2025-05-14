#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>> &vec, vector<int> &ans, int curr = 1) {
  if(curr >= vec.size()) return;
  if(vec[curr].size() == 0){
    ans[curr] = 0;
    return;
  }
  // cout<<curr<<"\n";
  ans[curr] = 0;
  for(auto v: vec[curr]) {
    solve(vec, ans, v);
    ans[curr] += 1 + ans[v];
  }
  return;
}

int main() {
  int n,x;
  cin >> n;
  vector<vector<int>> vec(n+1);
  vector<int> ans(n+1);
  for(int i = 2; i <= n; i++) {
    cin>>x;
    vec[x].push_back(i);
  }
  solve(vec, ans);
  for(int i = 1; i <= n; i++) {
    cout<<ans[i]<<" ";
  }
}