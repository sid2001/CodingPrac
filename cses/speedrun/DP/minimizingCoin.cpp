#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve(int target,vector<int> &coins,int curr,int count,int &ans){
  if(target==0){
    ans = min(ans,count);
    return;
  }
  if(target<0) return;
  if(curr>=coins.size()) return;
  if(count>=ans) return;

  // for(int i = curr; i<coins.size(); i++){
  solve(target-coins[curr],coins,curr,count+1,ans);
  solve(target,coins,curr+1,count,ans);
  // }

}

int main(){
  int n, target,ans=INT_MAX;
  cin>>n>>target;
  vector<vector<int>> dp(target+1, 0);
  vector<int> coins(n);
  for(int i = 0; i<n; i++){
    cin>>coins[i];
  }
  solve(target,coins,0,0,ans);
  cout<<(ans==INT_MAX?-1:ans)<<"\n";
}