#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy [4] = {0,1,0,-1};

void bfs(vector<vector<char>> &grid,vector<vector<int>> &visited, int x,int y){
  int cx,cy;
  queue<pair<int,int>> q;
  q.push({x,y});
  visited[x][y] = 1;

  while(!q.empty()){
    cx = q.front().first;
    cy = q.front().second;

    q.pop();
    for(int i=0;i<4;i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if(nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '.' && !visited[nx][ny]){
        visited[nx][ny] = 1;        
        q.push({nx,ny});
      }
    }
  }

  return;
}
int main(){
  int x,y,rooms = 0;
  string str;
  cin>>x>>y;
  vector<vector<char>> grid;
  vector<vector<int>> visited;

  grid.resize(x, vector<char>(y));
  visited.assign(x,vector<int>(y,0));

  for(int i=0;i<x;i++){
    cin>>str;
    for(int j=0;j<y;j++){
      grid[i][j]=str[j];
    }
  }

  for(int i = 0;i<x;i++){
    for(int j = 0;j<y;j++){
      if(grid[i][j] == '.' && !visited[i][j]){
        ++rooms;
        bfs(grid,visited,i,j);
      }
    }
  }
  cout<<rooms<<endl;
  return 0;
}