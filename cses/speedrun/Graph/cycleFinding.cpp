#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#define ll long long
using namespace std;
// struct node{
//   int parent;
//   ll dist;
//   bool visited;
//   int time;
// };
// void trace(vector<node> &vec, int curr, int s){
//   cout<<s+1<<" ";
//   vector<int> v;
//   int x = curr;
//   while(x != s){
//     //cout<<x<<" ";
//     //cout<<x+1<<" ";
//     //cout<<"parent: "<<vec[x].parent<<"\n";
//     v.push_back(x);
//     x = vec[x].parent;
//   }
//   for(int i = v.size()-1;i>=0; i--){
//     cout<<v[i]+1<<" ";
//   }
//   cout<<s+1<<"\n";
// }
// void solve(vector<vector<pair<int,ll>>> &adj){
//   vector<node> vec(adj.size(),{-1,LLONG_MAX,0,-1});
//   vec[0] = {0,0,1}; 
//   stack<pair<node,int>> q;
//   q.push({node{0,0,0,0},0});
//   int curr; node n;
//   while(!q.empty()){
//     auto x = q.top();
//     n = x.first;
//     //vec[x.second].visited = true;
//     curr = x.second;
//     // cout<<"At "<<curr+1<<"\n";
//     q.pop();
//     for(auto v : adj[curr]){
//       if(!vec[v.first].visited){
//         //cout<<"Visiting "<<v.first<<"\n";
//         vec[v.first].visited = true;
//         vec[v.first].time = vec[curr].time + 1;
//         vec[v.first].parent = curr;
//         vec[v.first].dist = v.second + vec[curr].dist;
//         q.push({vec[v.first],v.first});
//       }else if(vec[v.first].time > vec[curr].time){
//         //cout<<"Already visited "<<v.first<<"\n";
//         //cout<<"curr dist: "<<vec[curr].dist<<" v dist: "<<vec[v.first].dist<<"parent: "<<vec[v.first].parent<<"\n";
//         // cout<<"parent dist: "<<vec[vec[v.first].parent].dist<<"\n";
//         // cout<<"sds"<<"\n";
//         //ll ld = vec[curr].dist + v.second - vec[vec[v.first].parent].dist;
//         if(n.dist + v.second < vec[v.first].dist){
//           cout<<"v.first "<<n.dist + v.second<<"curr: "<<vec[v.first].dist<<"\n";
//           cout<<"YES"<<"\n";
//           trace(vec,curr,v.first);
//           return;
//         }
//       }else if(vec[v.first].time < vec[curr].time){
//         vec[v.first].parent = curr;
//         vec[v.first].dist = v.second + vec[curr].dist;
//         q.push({vec[v.first],v.first});
//       }
//     }
//   }
//   cout<<"NO"<<"\n";
// }

void dfs(vector<vector<pair<int, ll>>> &adj, vector<ll> &visited,bool &flag, ll time,vector<pair<int,ll>> &path, int &start , int curr = 0){

  for(auto v : adj[curr]) {
    if(visited[v.first] && visited[v.first] > time + v.second) {
      flag = true;
      start = v.first;
      path.push_back({curr,v.second});
      return;
    }else if(!visited[v.first]){
      visited[v.first] = time + v.second;
      dfs(adj,visited,flag,time + v.second,path,v.first,curr);
      if(flag&&start == curr) {
        path.push_back({curr,v.second});
        return;
      }else if(flag) {
        path.push_back({curr,v.second});
      }
    }
  }
}

int main() {
  int n, m,a,b;
  ll x;
  cin >> n >> m;
  vector<vector<pair<int, ll >>> adj(n);
  for(int i = 0; i < m; i++) {
    cin >> a>>b>>x;
    adj[a-1].push_back({b-1,x});
  }
  // solve(adj);
  vector<ll> visited(n,0);
  bool flag = false;
  vector<pair<int,ll>> path;
  int start = -1;
  dfs(adj,visited,flag,1,path,start);
  if(flag) {
    cout<<"YES"<<"\n";
    cout<<path.size()<<"\n";
    for(auto v : path) {
      cout<<v.first+1<<" "<<v.second<<"\n";
    }
  }else {
    cout<<"NO"<<"\n";
  }
}