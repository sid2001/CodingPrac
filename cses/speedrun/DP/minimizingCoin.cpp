#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minimizeCoins(vector<int> &vec, vector<vector<int>> &dp, int x) {
  for(int i = 1; i <= x; i++) {
    if(vec[0]<=i) {
      dp[0][i] = 1 + dp[0][i-vec[0]];
    } else {
      dp[0][i] = 1e6 + 1;
    }
  }
  for(int i = 1; i < vec.size(); i++) {
    for(int j = 1; j <= x; j++) {
      if(vec[i]<= j) {
        dp[i][j] =min(1 + dp[i][j-vec[i]], dp[i-1][j]);
      }
      else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[vec.size() -1][x];
}

void solve(int n,int x){
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin>>vec[i];
  }
  sort(vec.begin(), vec.end());
  vector<vector<int>> dp(n,vector<int>(x+1,0));
  int ans = minimizeCoins(vec,dp,x);
  cout<<(ans<=1e6?ans:-1);
  return;
}

int main(){
  int n,x;
  cin>>n>>x;
  solve(n,x);
}


// int solve(vector<int> &vec, int x, int idx,vector<vector<int>> &dp) {
//   if(idx == 0) {
//     if(x % vec[idx] == 0) return x / vec[0];
//     else return 1e6 + 1;
//   }

//   if(dp[idx][x] != -1) return dp[idx][x];

//   int skip = 0 + solve(vec,x,idx-1,dp);
//   int not_skip = 1e6 + 1; 
//   if(vec[idx] <= x) {
//     not_skip = 1 + solve(vec,x-vec[idx],idx,dp); 
//   }

//   return dp[idx][x] = min(skip,not_skip);
// }

// int comparefn(int l1, int l2) {
//   if(l1>l2) return 0;
//   else return 1;
// }

// int main() {
//   int n, x;
//   cin>>n>>x;

//   vector<int> vec(n);
//   vector<vector<int>> dp(n, vector<int>(x+1,-1));
//   for(int i = 0; i < n; i++) {
//     cin>>vec[i];
//   }

//   sort(vec.begin(),vec.end(),comparefn);
//   int ans = solve(vec,x,n-1,dp);
//   cout<<(ans>1e+6?-1:ans);
// }

