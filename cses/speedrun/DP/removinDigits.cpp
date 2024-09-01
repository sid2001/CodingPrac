#include <iostream>
#include <vector>

using namespace std;

int minimumSteps(vector<int> &vec, int s) {
  vector<vector<int>> dp(vec.size()+1,vector<int>(s+1,0));

  for(int i = 0; i<vec.size();i++){
    for(int j = 1; j <= s; j++){
      dp[i][j] = 1e6 + 1;
      int l = 1e6+1, ll = 1e6 +1;
      if(i>0 && j >= vec[i])
        l = dp[i-1][j - vec[i]];
      if(j>=vec[i])
        dp[i][j] = min(l,dp[i][j-vec[i]]);
        dp[i][j] += 1;
    }
  }

  return dp[vec.size()-1][s];
}
void solve(int n){
  vector<int> vec;
  int ss = n;
  while(n>0){
    if(n%10!=0){
      vec.push_back(n%10);
    }
    n/=10;
  }
  cout<<minimumSteps(vec,ss);
}
int main() {
  int n;
  cin>>n;
  solve(n);
}