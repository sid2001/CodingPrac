#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

void bfs(vector<vector<int>> &grid, vector<int> &visited, int x,int &lastCity){
  queue<int> q;
  q.push(x);
  
  while(!q.empty()){
    int cx = q.front();
    lastCity = cx;
    q.pop();
    visited[cx] = 1;
    for(int i = 0; i < grid[cx].size(); i++){
      if(!visited[grid[cx][i]]){
        q.push(grid[cx][i]);
      }
    }
  }
  
  return;
}

int main(){
  int c,r;
  int nroads = 0, lastCity = -1;
  cin>>c>>r;

  vector<vector<int>> grid(c);
  vector<int> visited(c,0);
  vector<pair<int,int>> roads;

  for(int i = 0; i < r; i++){
    int x,y;
    cin>>x>>y;
    grid[x-1].push_back(y-1);
    grid[y-1].push_back(x-1);
  }
  for(int i = 0; i < grid.size(); i++){
    if(!visited[i]){
      if(lastCity != -1){
        nroads++;
        roads.push_back({lastCity,i});
      }
      bfs(grid,visited,i,lastCity);
    }
  }
  cout<<nroads<<"\n";
  for(int i = 0; i < roads.size(); i++){
    cout<<roads[i].first + 1<<" "<<roads[i].second + 1<<"\n";
  }
  return 0;
}