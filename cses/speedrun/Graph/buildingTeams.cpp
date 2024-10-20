#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int color(vector<vector<int>> &vec, vector<int> &colored, int curr) {
  queue<int> q;
  q.push(curr);
  int team = 0;

  while(!q.empty()) {
    int x = q.front();
    q.pop();
    if(colored[x] != -1) {
      team = !colored[x];
    }else{
      colored[x] = team;
      team = !team;
    }
    for(int i = 0; i < vec[x].size(); i++) {
      if(colored[vec[x][i]] !=-1 && colored[vec[x][i]] != team) return -1;
      else if(colored[vec[x][i]] == -1) {
        colored[vec[x][i]] = team;
        q.push(vec[x][i]);
      }
    }
  }
  return 1;
}

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> vec(n+1);
  int a,b;
  for(int i = 0;i < m;i++){
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  vector<int> colored(n+1,-1);
  int ans;
  for(int i = 1;i <= n ; i++) {
    if(colored[i] == -1)
      ans = color(vec, colored, i);
      if(ans == -1) {
        cout<<"IMPOSSIBLE";
        return 0;
      }
  }
  for(int i = 1; i <= n; i++) {
    cout<<colored[i]+1<<" ";
  }
}