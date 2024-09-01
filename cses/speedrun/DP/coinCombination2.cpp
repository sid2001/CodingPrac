#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000007
using namespace std;

int coinCombinations(vector<int> &vec, vector<vector<int>> &dp, int idx, int amt) {
  if(amt == 0) return 1;
  if(idx>=(int) vec.size()|| amt < 0) return 0;
  if(amt<vec[idx]) return 0;

  //cout<<idx<<" "<<amt<<"\n";
  if(dp[idx][amt]!= -1) return dp[idx][amt];
  int moves = 0;
  for(int i = idx; i < (int) vec.size(); i++) {
    moves = (moves + coinCombinations(vec, dp, i, amt-vec[i]))%MOD;
  }
  return dp[idx][amt] = moves; 
}

int solve(int n, int x) {
  vector<int> vec(n,0);
  for(int i = 0; i<n;i++){
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end());
  vector<vector<int>> dp(n,vector<int>(x+1,-1));

  return coinCombinations(vec,dp,0,x);
}

int main(){
  int n, x;
  cin>>n>>x;
  cout<<solve(n,x);

  return 0;
}