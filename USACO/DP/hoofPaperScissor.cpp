//https://usaco.org/index.php?page=viewproblem2&cpid=694
#include <iostream>
#include <vector>
#include <fstream>
#define ll long long
using namespace std;

ll maxWins(vector<char> &vec,int k,vector<vector<ll>> &dp, int curr = 0,int h = 0,int p = 0, int s = 0,int ans = 0) {
  if(curr>=vec.size()) {
    return ans+max(h,max(p,s));
  }
  
  ll t1 = -1;
  ll t2 = -1;
  //if(dp[k][curr] != -1) return dp[k][curr];
  if(vec[curr]=='H'){
    h++;
  }else if(vec[curr]=='P') {
    p++;
  }else{
    s++;
  }
  t1 = maxWins(vec, k,dp, curr+1,h,p,s,ans);
  if(k>0) {
    t2 = maxWins(vec,k-1,dp,curr+1,0,0,0,ans+max(h,max(p,s)));
  }

  return dp[k][curr] = max(t1,t2);
}

void solve() {
  int n,k;
  ifstream inputFile("hps.in");
  inputFile>>n>>k;
  vector<char> vec(n);
  for(int i = 0; i<n; i++) {
    inputFile>>vec[i];
  }
  inputFile.close();
  vector<vector<ll>> dp(k+1,vector<ll>(n+1,-1));
  for(int i = 0;i<k+1;i++) {
    for(int j = 0;j<n+1;j++) {
      dp[i][j] = -1;
    }
  }
  int ans = maxWins(vec,k,dp);
  FILE* fp = fopen("hps.out","w");
  fprintf(fp,"%d",ans);
  fflush(fp);
  fclose(fp);
  return;
}


int main() {
  solve();
  return 0;
}