#include <iostream>
#include <vector>

using namespace std;

vector<int> stage = {1,5,4,3};
vector<int> dx = {0,1,0,-1};
vector<int> dy = {1,0,-1,0};

void traverse(vector<vector<int>> &vec, int k,int &ans) {
  int state = 0;
  for(int i = k; i < vec[0].size()-k; i++) {
    if(vec[k][i] == stage[state]) {
      if(state == 3) ans++;
      state = (++state)%4;
    }else{
      state = 0;
      if(vec[k][i] == stage[state]) {
        state++;
      }
    }
  }

  for(int i = k+1; i < vec.size()-k; i++) {
    if(vec[i][vec[0].size()-k-1] == stage[state]) {
      if(state == 3) ans++;
      state = (++state)%4;
    }else{
      state = 0;
      if(vec[i][vec[0].size()-k-1] == stage[state]) {
        state++;
      }
    }
  }

  for(int i = vec[0].size()-k-1; i >= k; i--) {
    if(vec[vec[0].size()-1-k][i] == stage[state]) {
      if(state == 3) ans++;
      state = (++state)%4;
    }else{
      state = 0;
      if(vec[vec[0].size()-1-k][i] == stage[state]) {
        state++;
      }
    }
  }
  for(int i = vec.size()-k-1; i >= k; i--) {
    if(vec[i][k] == stage[state]) {
      if(state == 3) ans++;
      state = (++state)%4;
    }else{
      state = 0;
      if(vec[i][k] == stage[state]) {
        state++;
      }
    }
  }
  int idx = 3;
  for(int i = k; i < vec[0].size()-k; i++) {
    if(k==0) break;
    if(vec[k][i] == stage[state]) {
      if(state == 3) ans++;
      state = (++state)%4;
    }else{
      state = 0;
      if(vec[k][i] == stage[state]) {
        state++;
      }
    }
    k--;
  }
}

void solve() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> vec(n,vector<int>(m,0));
  int x;
  for(int i = 0; i < n; i++) {
    cin>>x;
    for(int j = 0; j < m; j++) {
      vec[i][j] = x%10;
      x /= 10;
    }
  }
  int ans = 0;
  int turn = n/2;
  int k = 0;
  while(k < turn){
    traverse(vec,k,ans);
    k++;
  }
  cout<<ans<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}