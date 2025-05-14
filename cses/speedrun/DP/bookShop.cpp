#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<pair<int,int>> &book, vector<int> &page, vector<vector<int>> &dp, int x) {
  for(int i = 1; i < dp.size(); i++) {
    for(int j = 1; j <= x; j++){
      if(book[i-1].first<=j) {
        dp[i][j] = max(dp[i-1][j-book[i-1].first]+ book[i-1].second,dp[i-1][j]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  return dp[dp.size()-1][x];
}

int main() {
  int n, x;
  cin>>n>>x;
  vector<pair<int,int>> book(n,{0,0});
  vector<int> page(n,0);
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for(int i = 0;i<n;i++){
    cin>>book[i].first;
  }
  for(int i = 0; i < n; i++) {
    cin>>book[i].second;
  }
  sort(book.begin(),book.end());
  cout<<solve(book, page, dp,x);
}