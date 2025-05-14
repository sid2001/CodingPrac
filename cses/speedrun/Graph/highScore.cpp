#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>

#define ll long long

using namespace std;

int relax(vector<vector<pair<int,ll>>> &edge, vector<ll> &dist,vector<int> &connected) {
  int flag = 0;
  for(int i = 0; i < edge.size(); i++) {
    for(auto e : edge[i]) {
      if(dist[e.first] > dist[i] + e.second && dist[i] != LLONG_MAX){
        // cout<<"e "<< dist[e.first]<<" i "<< dist[i]<<" ";
        if(connected[e.first])
          flag = 1;
        dist[e.first] = dist[i] + e.second;
        // cout<<"Relaxing "<<e.first+1<<" from "<<i+1<<" dist "<< dist[e.first]<<"\n";
      }
    }
  }
  return flag;
}

void mark(vector<vector<pair<int,int>>> &parent,vector<int> &connected,int pa, int pb){
  int temp;
  while(pa != pb) {
    connected[pa] = 1;
    connected[pb] = 1;
    temp = pa;
    pa = parent[pa][pb].first;
    pb = parent[temp][pb].second;
  }
}
void dfs(vector<vector<int>> &visited, vector<int> &connected, vector<vector<pair<int,ll>>> &edge,vector<vector<pair<int,int>>> &parent,int curr = 0,int pa = 0, int pb = 0) {
  for(auto v : edge[curr]) {
    if(!visited[curr][v.first]) {
      parent[curr][v.first] = {pa,pb};
      if(v.first==edge.size()-1) mark(parent, connected,curr,v.first);
      visited[curr][v.first] = 1;
      dfs(visited,connected,edge,parent,v.first,curr,v.first);
    }else if(connected[curr]){
      //cout<<"aga "<<pa<<" "<<curr<<"\n";
      mark(parent, connected,pa,curr);
      return;
    }
  }
}

int main() {
  int n, m,a,b;
  ll x;
  cin>>n>>m;
  vector<ll> dist(n, LLONG_MAX);
  vector<vector<pair<int,ll>>> edge(n);
  for(int i = 0; i < m; i++) {
    cin>>a>>b>>x;
    edge[a-1].push_back({b-1,-x});
  }
  dist[0] = 0;
  vector<vector<int>> visited(n,vector<int>(n,0));
  vector<int> connected(n,0);
  connected[0] = 1;
  vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(n));
  dfs(visited,connected, edge,parent);
  for(int i = 0; i < n-1; i++) {
    if(!relax(edge, dist,connected)) break;
  }
  ll ans = dist[n-1];
  if(relax(edge,dist,connected)){
    cout<< -1 <<"\n";
  }else{
    cout<< -ans<<"\n";
  }
}