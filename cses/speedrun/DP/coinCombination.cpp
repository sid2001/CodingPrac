#include <iostream>
#include <vector>

#define ull int
#define MOD 1000000007
using namespace std;

ull coinCombinations(vector<int> &vec, vector<int> &dp,int idx,int amt) {
  if(amt < 0) return 0;
  else if(amt == 0 ) return 1;

  if(dp[amt]!= -1) return dp[amt];
  ull moves = 0;
  for(int i = 0; i < (int) vec.size(); i++) {
      moves += coinCombinations(vec,dp,idx,amt-vec[i]);
      moves = moves % MOD;
  }

  return dp[amt] = moves;
}

ull solve(int n, int x){
  vector<int> vec(n,0);
  for(int i = 0;i<n;i++){
    cin >> vec[i];
  }
  //vector<vector<int>> coins();
  vector<int> dp(x+1,-1);
  for(int i = 0; i<(int)dp.size();i++){
    dp[i] = -1;
  }
  return coinCombinations(vec,dp,0,x);
}

int main() {
  int n, x;
  cin >> n >> x;
  cout<<solve(n,x);
}