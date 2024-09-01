#include<iostream>
#include<vector>

using namespace std;


// void display(vector<vector<int>> a) {
//   for(int i = 0; i < a.size(); i++) {
//     for(int j = 0; j < a[0].size(); j++) {
//       cout<<a[i][j]<<" ";
//     }
//     cout<<"\n";
//   }
//   cout<<"\n";
//   return;
// }
int minMoves(vector<int> &a, vector<int> &b, int k, int moves, int score, int idx, int ca, int cb,vector<vector<int>> &dp) {
  if(k<=0) {
    //cout<<k<<": score"<<"\n";
    return 0;
  }
  if(idx == a.size()) {
    return 1e9;
  }
  if(dp[idx][k] != 1e9) {
    return dp[idx][k];
  }
  int skip = 1e9;
  skip = minMoves(a,b,k,moves,score,idx+1,a[idx+1],b[idx+1],dp);
  //skip = 1e9;
  int notSkip = 1e9;
  if(ca > 0 && cb > 0) {
    if(ca > cb) {
      notSkip = cb + minMoves(a,b,k-1,moves,score,idx,ca-1,cb,dp);
    } else {
      if(ca == 1 && cb == 1) {
        notSkip = ca;
        notSkip += minMoves(a,b,k-2,moves,score,idx+1,a[idx+1],b[idx+1],dp);
      } else {
        notSkip = ca + minMoves(a,b,k-1,moves,score,idx,ca,cb-1,dp);
      }
    }
  }
  //cout<<"skip :"<<skip<<"not skip: "<<notSkip<<"\n";
  return dp[idx][k] = min(skip,notSkip);
  //return min(skip,notSkip);
}
void solve() {
  int n, k;
  cin>>n>>k;
  vector<int> a(n,0);
  vector<int> b(n,0);
  vector<vector<int>> dp(n+1,vector<int>(k+1,1e9));

  for(int i = 0; i < n; i++) {
    cin>>a[i];
    cin>>b[i];
  }
  int moves = 1e9;
  int score = 0;
  int idx = 0;
  int ans = minMoves(a,b,k,moves,score,idx,a[idx],b[idx],dp);
  if(ans == 1e9) cout << -1 << "\n";
  else cout << ans << "\n";
  //display(dp);
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}