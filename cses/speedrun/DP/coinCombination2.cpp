#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000007
using namespace std;

int coinCombinations(vector<int> &vec, vector<vector<int>> &dp, int idx, int amt) {
  if(amt == 0) return 1;
  if(idx>=(int) vec.size()|| amt < 0) return 0;

  for(int i = 0;i<(int)vec.size();i++) {
    dp[i][0] = 1;
  }
  for(int i = 0;i<vec.size();i++) {
    for(int j = 1;j<=amt;j++) {
      dp[i][j] = 0;
      if(i > 0) dp[i][j] = dp[i-1][j];
      if(j >= vec[i])
        dp[i][j] += dp[i][j-vec[i]];
        dp[i][j] %= MOD;
    }
  }
  return dp[vec.size()-1][amt];
}

int solve(int n, int x) {
  vector<int> vec(n,0);
  for(int i = 0; i<n;i++){
    cin>>vec[i];
  }
  vector<vector<int>> dp(n,vector<int>(x+1,-1));

  return coinCombinations(vec,dp,0,x);
}

int main(){
  int n, x;
  cin>>n>>x;
  cout<<solve(n,x);

  return 0;
}