#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char dir[4] = {'D','L','U','R'};
map<char,int> mp = {{'D',2},{'L',3},{'R',1},{'U',0}};

void printPath(vector<vector<char>> &visited, int sx, int sy,int x, int y) {
  cout<<"YES"<<"\n";
  // cout<<"xy"<<x<<" "<<y<<"\n";
  int xx,yy;
  while(x!=sx||y!=sy) {
    cout<<visited[sx][sy];
    // cout<<" "<<sx<<" "<<sy<<"\n";
    xx = sx;
    yy = sy;
    sx += dx[mp[visited[xx][yy]]];
    sy += dy[mp[visited[xx][yy]]];
    // cout<<" "<<sx<<" "<<sy<<"\n";
  }
  return;
}

int path(vector<vector<char>> &vec, int x, int y) {
  queue<pair<int,int>> q;
  vector<vector<char>> visited(vec.size(),vector<char>(vec[0].size(),'0'));
  q.push({x,y});
  while(!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if(nx < vec.size()-1 && ny < vec[0].size()-1 && visited[nx][ny] == '0' && vec[nx][ny] != '#') {
        if(vec[nx][ny] == 'A') {
          visited[nx][ny] = dir[i];
          // cout<<nx<<" "<<ny<<" "<<dir[i]<<"\n";
          printPath(visited,nx,ny,x,y);
          return 1;
        }else if(vec[nx][ny] == '.') {
          visited[nx][ny] = dir[i];
          // cout<<nx<<" "<<ny<<" "<<dir[i]<<"\n";
          q.push({nx,ny});
        }else return -1;
      }
    }
  }
  return 0;
}

int main() {
  int m,n;
  cin>>m>>n;
  vector<vector<char>> vec(m,vector<char>(n));
  char c;
  vector<vector<int>> tar;
  int sx, sy;
  for(int i = 0;i<m;i++) {
    for(int j = 0; j < n; j++) {
      cin>>vec[i][j];
      if((i==m-1||j==n-1)&&vec[i][j]=='.'){
        tar.push_back({i,j});
      }
      if(vec[i][j] == 'A') {
        sx = i;
        sy = j;
      }
    }
  }
  for(int i = 0; i < tar.size(); i++) {
    int ans = path(vec,tar[i][0],tar[i][1]);
    if(ans == 1) {
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}