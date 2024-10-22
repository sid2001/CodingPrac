#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
#define ull unsigned long long

template <class T> void display(vector<T> &vec){
  int d = 0;
  for(T v: vec){
    if(!d++) continue;
    cout<<v<<" ";
  }
  return;
}

void shortestPath(vector<vector<pair<ull,ull>>> &vec, vector<ull> &dist, priority_queue<pair<ull,ull>,vector<pair<ull,ull>>, greater<pair<ull,ull>>> &pq){
  while(!pq.empty()){
    ull x = pq.top().second;
    ull currDist = pq.top().first;
    pq.pop();

    if(currDist > dist[x]) {
      continue;
    }

    for(auto v : vec[x]) {
      ull w = v.second;
      ull node = v.first;
      if(dist[node] > currDist + w){
        dist[node] = currDist + w;
        pq.push({dist[node],node});
      }
    }
  }
}

using namespace std;
int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<pair<ull, ull>>> vec(n+1);
  ull a,b,c;
  for(int i = 0; i < m; i++) {
    cin>>a>>b>>c;
    vec[a].push_back({b,c});
  }
  vector<ull> dist(n+1,ULLONG_MAX);
  dist[1] = 0;
  priority_queue<pair<ull,ull>, vector<pair<ull,ull>>, greater<pair<ull,ull>>> pq;
  for(int i = 1; i < n +1; i++) {
    pq.push({dist[i],i});
  }
  shortestPath(vec, dist,pq);
  display(dist);
}