#include<iostream>
#include <vector>

using namespace std;

void solve2(vector< int* > &dp,vector<int> &vec,string &st,int curr) {

  int c = curr;
  int* ptr = new int;
  *ptr = 0;
  while(true){
    //cout<<"m";
    dp[curr] = ptr;
    if(st[curr-1]=='0') {
      *ptr += 1;
    }
    curr = vec[curr];
    if(curr == c) break;
    if(curr == vec[curr]) break;
  }
  return;
}

void solve() {
  int n;
  cin>>n;
  vector<int> vec(n+1,0);
  vec[0] = 0;
  for(int i = 1; i<=n; i++) {
    cin>>vec[i];
  }
  string color;
  cin>>color;
  
  vector<int*> dp(n+1,NULL);

  for(int i = 1;i <= n; i++) {
    if(dp[i] == NULL)
      solve2(dp,vec,color,i);
  }

  for(int i = 1; i<=n;i++) {
    std::cout<<*(dp[i])<<" ";
  }
  for(int i = 1; i<=n;i++) {
    dp[i] = NULL;
  }
  std::cout<<"\n";
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}