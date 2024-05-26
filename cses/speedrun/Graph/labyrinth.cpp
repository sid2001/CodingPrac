#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
 
using namespace std;
 
// void display(vector<vector<char>> &maze){
//   for(int i = 0; i < maze.size(); i++){
//     for(int j = 0; j < maze[0].size(); j++){
//       cout<<maze[i][j];
//     }
//     cout<<endl;
//   }
// }
char dir[4] = {'U','R','D','L'};
int ndir[4] = {0,1,2,3};
int rdir[4] = {2,3,0,1};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char myPath[1000000]; 
void getPathAndMoves(int xd,int yd,vector<vector<int>> &path){
  int idir = path[xd][yd];
  string pa = "";
  int moves = 0;
  while(idir != -1){
    myPath[moves] = dir[idir];
    moves++;
    // pa = dir[idir] + pa;
    xd = xd + dx[rdir[idir]];
    yd = yd + dy[rdir[idir]];
    idir = path[xd][yd];
  }

  reverse(myPath, myPath + moves);
  cout << moves << "\n";
  for(int i = 0; i < moves; i++){
    cout<<myPath[i];
  }
  cout << "\n";
}
int bfs(vector<vector<char>> &maze, vector<vector<int>> &visited,vector<vector<int>> &path, int x, int y){
  queue<pair<int,int>> q;
  q.push({x,y});
  visited[x][y] = 1;
 
  while(!q.empty()){
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();
 
    for(int i = 0; i < 4; i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];
 
      if(nx < maze.size() && nx >= 0 && ny < maze[0].size() && ny >= 0 && !visited[nx][ny] && (maze[nx][ny] == '.' || maze[nx][ny] == 'B')){
        path[nx][ny] = ndir[i];
        visited[nx][ny] = 1;
        if(maze[nx][ny]=='B'){
          return 1;
        }
        q.push({nx,ny});
      }
    }
  }
  return 0;
}
int main(){
  int n,m,xd,yd;
  int flag = 0;
  cin>>n>>m;
  vector<vector<char>> maze(n,vector<char>(m));
  vector<vector<int>> visited(n,vector<int>(m,0));
  vector<vector<int>> path(n,vector<int>(m,-1));
 
  int sx, sy;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>maze[i][j];
      if(maze[i][j]=='A'){
        sx = i;
        sy = j;
      }
      if(maze[i][j] == 'B') {
        xd=i;
        yd=j;
      }
    }
  }
  
  flag = bfs(maze,visited,path,sx,sy);

  if(flag){
    cout<<"YES"<<"\n";
    getPathAndMoves(xd,yd,path);
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}