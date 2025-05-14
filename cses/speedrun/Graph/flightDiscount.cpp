#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define ll long long

using namespace std;

void solve(vector<vector<pair<int,ll>>> &adj){
  struct Pos{
    int pos;
    bool used;
    ll cost;
  };
  auto cmp = [&](const Pos &a, const Pos &b){return a.cost > b.cost;};
  priority_queue<Pos, vector<Pos>, decltype(cmp)> pq(cmp);
  vector<vector<ll>> min_cost(adj.size(),{LLONG_MAX,LLONG_MAX});
  min_cost[0] = {0,0};
  pq.push({0,false,0});
  while(!pq.empty()){
    Pos curr = pq.top();
    pq.pop();
    ll curr_cost = min_cost[curr.pos][curr.used];
    if(curr_cost < curr.cost) continue;
    if(curr.pos==adj.size() - 1) break;

    for(auto v : adj[curr.pos]){
      ll w = v.second; 
      if(!curr.used) {
        if(w/2 + curr.cost < min_cost[v.first][true]){
          min_cost[v.first][true] = w/2 + curr.cost;
          pq.push(Pos{v.first,true,w/2+curr.cost});
        }

        if(w+curr.cost < min_cost[v.first][false]) {
          min_cost[v.first][false] = w + curr.cost;
          pq.push(Pos{v.first,false,w+curr.cost});
        }
      }else{
        if(w+curr.cost < min_cost[v.first][true]) {
          min_cost[v.first][true] = w + curr.cost;
          pq.push(Pos{v.first,true,w+curr.cost});
        }
      }
    }
  }
  cout<<min_cost[adj.size() - 1][true]<<"\n";
}

int main() {
  int n, m,a,b;
  ll x;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> adj(n);
  for(int i = 0; i < m; i++) {
    cin>>a>>b>>x;
    adj[a-1].push_back({b-1,x});
  }
  solve(adj);
}