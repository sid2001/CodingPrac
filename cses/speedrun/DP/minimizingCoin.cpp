#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solve(vector<int> &vec, int x, int idx,vector<vector<int>> &dp) {
  if(idx == 0) {
    if(x % vec[idx] == 0) return x / vec[0];
    else return INT_MAX;
  }

  if(dp[idx][x] != -1) return dp[idx][x];

  int skip = 0 + solve(vec,x,idx-1,dp);
  int not_skip = INT_MAX; 
  if(vec[idx] <= x) {
    not_skip = 1 + solve(vec,x-vec[idx],idx,dp); 
  }

  return dp[idx][x] = min(skip,not_skip);
}

int comparefn(int l1, int l2) {
  if(l1>l2) return 1;
  else return 0;
}

int main() {
  int n, x;
  cin>>n>>x;

  vector<int> vec(n);
  vector<vector<int>> dp(n, vector<int>(x+1,-1));
  for(int i = 0; i < n; i++) {
    cin>>vec[i];
  }

  sort(vec.begin(),vec.end(),comparefn);
  int ans = solve(vec,x,n-1,dp);
  cout<<(ans>=INT_MAX?-1:ans);
}
