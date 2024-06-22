#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

pair<int,int> newTeam(vector<set<int>> &nTeam, int &teams,int curr){
  set<int>::iterator itr;
  int len = nTeam[curr].size();
  itr = nTeam[curr].begin();
  // if(nTeam[curr].size()==0){
  //   if(teams==0){
  //     return {1,++teams};
  //   }else{
  //     return {0,0};
  //   }
  // }
  if(len==0&&teams>0){
    // cout<<"hello"<<"\n";
    return {0,0};
  }
  for(int i = 0; i<len; i++){
    // cout<<"h"<<*itr<<"\n";
    if(i!=*itr){
      // cout<<"hello2"<<"\n";
      return {0,i};
    }
    if(i==len-1&&i<teams-1){
      return {0,i+1};
    }
    itr++;
  }
  return {1,++teams};
}
void bfs(vector<vector<int>> &adj, vector<int> &visited, vector<set<int>> &nTeam, int start,int &teams){
  queue<int> q;
  q.push(start);
  int team;
  // pair<int,int> temp = newTeam(nTeam,teams,start);
  //   if(!temp.first){
  //     team = temp.second;
  //   }else{
  //     team = teams;
  //   }
  visited[start] = 1;
  while(!q.empty()){
    int curr = q.front();
    pair<int,int> temp = newTeam(nTeam,teams,curr);
    if(!temp.first){
      team = temp.second;
    }else{
      team = teams-1;
    }
    cout<<"team: "<<team<<" curr: "<<curr<<" teams: "<<teams<<"\n";
    visited[curr] = team+1;
    q.pop();
    for(int i = 0; i<adj[curr].size(); i++){
      if(!visited[adj[curr][i]]){
        visited[adj[curr][i]] = 1;
        q.push(adj[curr][i]);
        nTeam[adj[curr][i]].insert(team);
      }
    }
  }
}
int main(){
  int pupils, relations;
  cin >> pupils >> relations;
  int teams = 0;
  vector<vector<int>> adj(pupils);
  vector<int> visited(pupils, 0);
  vector<set<int>> nTeam(pupils);

  for(int i = 0; i < relations; i++){
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  for(int i = 0; i < pupils; i++){
    if(!visited[i]){
      bfs(adj,visited,nTeam,i,teams);
    }
  }
  // cout<<"teams: "<<teams<<"\n";
  for(int i = 0; i < pupils; i++){
    cout<<visited[i]<<" ";
  }
  return 0;
}