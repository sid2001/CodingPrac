#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

void display(vector<int> &vec) {
  for(auto i : vec) {
    cout<<i<<" ";
  }
  cout<<"\n";
  return;
}
void solve(vector<vector<pair<int,int>>> &adj, vector<int> &dist) {
  queue<int> q;
  vector<int> visited(adj.size(),0);
  q.push(1);
  visited[1] = 1;
  while(!q.empty()) {
    int i = q.front();
    q.pop(); 
    for(auto j : adj[i]) {
      if(dist[i-1] != 1e9+1){
        if(dist[j.first -1] > dist[i-1]+j.second) {
          q.push(j.first);
        }
        dist[j.first - 1] = min(dist[i- 1] + j.second, dist[j.first - 1]);
      }
      else{
        dist[j.first - 1] = j.second;
        q.push(j.first);
      }
    }
  }
  return;
}
int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n+1);
  vector<int> dist(n, 1e9 + 1);
  dist[0] = 0;
  int a,b,c;
  for(int i = 0; i < m; i++) {
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
  }
  solve(adj,dist);
  display(dist);

  return 0;
}