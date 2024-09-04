#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int dx[2] = {0,1};
int dy[2] = {1,0};
char path[4] = {'U','R','D','L'};

int solve(vector<vector<char>> &vec, vector<vector<int>> &dp, int cx,int cy,int n) {
  if(cx < 0 || cx >= n || cy < 0|| cy>= n || vec[cx][cy]=='*') return 0;
  if(cx == n-1 && cy == n-1) {
    //cout<<p<<'\n';
    return 1;
  }
  if(dp[cx][cy] != -1) return dp[cx][cy];
  dp[cx][cy] = 0;
  for(int i = 0; i < 2; i++){
    int nx = cx + dx[i];
    int ny = cy + dy[i];
    dp[cx][cy] = (int)(dp[cx][cy] + solve(vec, dp, nx,ny,n))%MOD;
  }

  return dp[cx][cy];
}
int main() {
  int n;
  cin>>n;
  vector<vector<int>> dp(n,vector<int>(n,-1));
  vector<vector<char>> vec(n,vector<char>(n,'.'));
  for(int i = 0; i<n;i++){
    for(int j = 0; j < n;j++){
      cin>>vec[i][j];
    }
  }
  cout<<solve(vec,dp,0,0,n);
  return 0;
}