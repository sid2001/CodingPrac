#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

void displayFlow(vector<vector<int>> &flow){
  for(int i = 0;i<flow.size();i++){
    for(int j = 0;j<flow.size();j++){
      cout<<flow[i][j]<<" ";
    }
    cout<<endl;
  }
}

int bfs(vector<vector<int>> &graph,vector<vector<int>> &residualCapacity, vector<int> &parent, int source, int destination){
  int n = graph.size();
  vector<int> visited(n,0);
  vector<int> queued(n,0);
  queue<int> q;
  q.push(source);
  parent[source] = -1;
  visited[source] = 1;
  int minFlow = INT_MAX;

  while(!q.empty()){
    int curr = q.front();
    visited[curr] = 1;
    for(int i = 0;i<graph.size();i++){
      if(residualCapacity[curr][i]>0 && !visited[i] && !queued[i]){
        parent[i] = curr;
        q.push(i);
        queued[i] = 1;
        minFlow = residualCapacity[curr][i]<minFlow?residualCapacity[curr][i]:minFlow;
        if(i==destination) return minFlow;
      }
    }
    q.pop();
  }
  return 0;
}
int edmondsKarp(vector<vector<int>> &graph, int source, int destination){
  int n = graph.size();
  vector<int> parent(n,-1);
  vector<vector<int>> residualCapacity(n,vector<int>(n,0));
  vector<vector<int>> flow(n,vector<int>(n,0));

  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      residualCapacity[i][j] = graph[i][j];
    }
  }
  while(int maxFlow = bfs(graph,residualCapacity,parent,source,destination)){
    int curr = destination;
    while(curr!=source){
      int prev = parent[curr];
      residualCapacity[prev][curr] -= maxFlow;
      residualCapacity[curr][prev] += maxFlow;
      curr = prev;
      if(graph[prev][curr]>0) flow[prev][curr] += maxFlow;
      else if(graph[curr][prev]>0) flow[curr][prev] -= maxFlow;
      // displayFlow(residualCapacity);
    }

  }
  int tFlow = 0;
  for(int i = 0;i<n;i++){
    tFlow += residualCapacity[i][source];
  }
  return tFlow;
}

int main(){
  int n;//number of nodes
  cin>>n;
  int source,destination;//source and destination
  vector<vector<int>> graph(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>graph[i][j];
    }
  }
  cin>>source>>destination;
  cout<<"Maximum Flow: "<<edmondsKarp(graph,source,destination)<<endl;
}