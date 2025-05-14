//https://codeforces.com/problemset/problem/1418/C
#include <iostream>
#include <vector>

using namespace std;

int minSkips(vector<int> &vec,vector<vector<int>> &dp,int curr = 0,int flag = 1) {
  if(curr >= vec.size()) return 0;
  int t1 = 1e6 + 1;
  int t2 = 1e6 + 1;

  if(dp[flag][curr] != -1) return dp[flag][curr];
  if(flag){
    t1 = vec[curr] + minSkips(vec,dp,curr+1,!flag);
    if(curr<vec.size()-1)
      t2 = vec[curr] + vec[curr+1] + minSkips(vec,dp,curr+2,!flag);
  } else {
    t1 = minSkips(vec,dp,curr+1,!flag);
    if(curr<vec.size()-1)
      t2 = minSkips(vec,dp,curr+2,!flag);
  }
  return dp[flag][curr] = min(t1,t2);
}
void solve() {
  int n;
  cin>>n;
  vector<int> vec(n);
  vector<vector<int>> dp(2,vector<int>(n,-1));
  for(int i = 0; i<n;i++) {
    dp[0][i] = -1;
    dp[1][i] = -1;
  }
  for(int i = 0; i<n;i++) {
    cin>>vec[i];
  }
  cout<<minSkips(vec,dp)<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}