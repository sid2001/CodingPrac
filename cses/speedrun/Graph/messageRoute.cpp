#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> parent(100000,-1);

void getRoute(int src, int dest){
  vector<int> path;
  path.push_back(dest);
  int curr = parent[dest];
  while(curr!=src){
    path.push_back(curr);
    curr = parent[curr];
  }
  path.push_back(src);
  cout<<path.size()<<"\n";

  for(int i = path.size()-1;i>=0;i--){
    cout<<path[i] + 1<<" ";
  }
}
void bfs(vector<vector<int>> &graph, int src, int dest, int &flag){
  vector<int> visited(graph.size(),0);
  queue<int> q;

  q.push(src);
  visited[src] = 1;
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    if(curr==dest){
      flag = 1;
      return;
    }
    for(int i = 0; i < graph[curr].size(); i++){
      int next = graph[curr][i];
      if(!visited[next]){
        parent[next] = curr;
        q.push(next);
        visited[next] = 1;
      }
    }
  }
  return;
}
int main(){
  int comp,conn,flag = 0;
  cin>>comp>>conn;
  vector<vector<int>> graph(comp);
  
  for(int i = 0;i<conn;i++){
    int x,y;
    cin>>x>>y;
    graph[x-1].push_back(y-1);
    graph[y-1].push_back(x-1);
  }

  bfs(graph,0,comp-1,flag); 
  if(flag) getRoute(0,comp-1);
  else cout<<"IMPOSSIBLE";

  return 0;
}