#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#define ll unsigned long long
using namespace std;

void solve(vector<vector<pair<int,ll>>> &adj,int dest,int k) {
  int n = adj.size();
  auto cmp = [&](const pair<int,ll> &a, const pair<int,ll> &b){return a.second > b.second;};
  priority_queue<pair<int,ll>, vector<pair<int,ll>>, decltype(cmp)> pq(cmp);
  //priority_queue<pair<int,ll>,vector<pair<int,ll>>, greater<pair<int, ll>>> pq;
  pq.push({0,0});
  // ll dist = -1;
  vector<ll> min_dist(n,LLONG_MAX);
  min_dist[0] = 0;
  while(!pq.empty()&&k) {
    auto curr = pq.top();
    pq.pop();
    // cout<<"curr "<<curr.first<<"\n";
    if(dest == curr.first) {
      k--;
      cout<<curr.second<<" ";
    }
    if(curr.second != min_dist[curr.first]) continue;

    for(auto v : adj[curr.first]){
      //cout<<"curr dist: "<<curr.second<<" w: "<<v.second<<" v "<<v.first<<"\n";
      if(curr.second + v.second < min_dist[v.first]) {
        min_dist[v.first] = curr.second+v.second;
      }
      pq.push({v.first,curr.second+v.second});
    }
  }
}

int main() {
  int n,m,k,a,b;
  ll c;
  cin>>n>>m>>k;
  vector<vector<pair<int,ll>>> adj(n);
  for(int i = 0; i < m; i++){
    cin>>a>>b>>c;
    adj[a-1].push_back({b-1,c});
  }
  solve(adj,n-1,k);
}