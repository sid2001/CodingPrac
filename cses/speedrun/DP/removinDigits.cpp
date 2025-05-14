#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &dp, int curr = 0) {
  //cout<<n<<"\n";
  if(n==0) {
    cout<<curr<<"\n";
    return curr;
  }
  if(dp[n] != -1) return dp[n];
  //cout<<n<<"\n";
  int num = n;
  int minStep = 1e6 + 1;
  //vector<int> selected(11,0);
  while(n>0) {
    while(n%10==0){
      n /=10;
    } 
      minStep = min(minStep,solve(num-n%10,dp, curr+1));
      cout<<"minStep: "<<minStep<<"\n";
    
    n /= 10;
  }
  return dp[num] = minStep;
}
int solve2(int n) {
  int num = n;
  int count = 0;
  while(n>0) {
    int maxi = -1;
    int nn = n;
    while(nn>0) {
      maxi = max(maxi,nn%10);
      nn /= 10;
    }
    n -= maxi;
    count++;
  }
  return count;
}
int main() {
  int n;
  cin>>n;
  int ans = 1e6+1;
  vector<int> dp(1e6+1,-1);
  cout<<solve2(n);
}