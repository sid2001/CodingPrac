#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<char> ans;
char dir[] = {'R', 'D', 'L', 'U'};
struct compare {
  bool operator()(vector<int>& a , vector<int>& b) {
    return a[0] > b[0];
  }
};
bool flag = false;
int count = 0;
void dfs(vector<vector<char>>& vec, vector<vector<int>>& monsters, int time, int cx , int cy, int n, int m) {
  if(cx == n - 1 || cx == 0 || cy == m - 1 || cy == 0) {
    flag = true;
    return;
  }
  monsters[cx][cy] = time;
  for(int i = 0; i < 4; i++) {
    int nx = cx + dx[i];
    int ny = cy + dy[i];
    if(nx < n && nx >= 0 && ny >= 0 && ny < m && vec[nx][ny] == '.' && monsters[nx][ny] > time + 1) {
        ans.push_back(dir[i]);
        dfs(vec, monsters, time + 1, nx, ny, n, m);
        if(flag) return;
        ans.pop_back();
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin>>n>>m;
  vector<vector<char>> vec(n, vector<char>(m));
  priority_queue<vector<int>, vector<vector<int>>, compare> pq;
  vector<vector<int>> monsters(n,vector<int>(m,INT_MAX));
  int sx, sy;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin>>vec[i][j];
      if(vec[i][j] == 'A') {
        sx = i; sy = j;
      }
      if(vec[i][j] == 'M') {
        pq.push({0, i, j});
      }
    }

  while(!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    if(monsters[curr[1]][curr[2]] < curr[0]) continue;
    monsters[curr[1]][curr[2]] = curr[0];

    for(int i = 0; i < 4; i++) {
      int nx = curr[1] + dx[i];
      int ny = curr[2] + dy[i];
      if(nx < n && nx >= 0 && ny >= 0 && ny < m && vec[nx][ny] == '.' && monsters[nx][ny] > curr[0] + 1) {
        monsters[nx][ny] = curr[0] + 1;
        pq.push({curr[0] + 1, nx, ny});
      }
    }
  }
    dfs(vec, monsters, 0, sx, sy,n ,m);
    if(!flag) cout<<"NO";
    else{
        cout<<"YES"<<"\n";
        cout<<ans.size()<<"\n";
        for(auto& a : ans) cout<<a;  
    } 
    return 0;
}