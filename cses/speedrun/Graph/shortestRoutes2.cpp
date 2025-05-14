#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

#define ll long long
using namespace std;

void minStackPush(stack<pair<int,ll>> &st,int i, ll c) {
  int j = st.top().first;
  ll jc = st.top().second;
  if(jc >= c) {
    st.push({i,c});
  }else{
    st.pop();
    st.push({i,c});
    st.push({j,jc});
  }
  return;
}

void solve(vector<vector<pair<int,ll>>> &vec, vector<vector<ll>> &dist, int curr){
  stack<pair<int,ll>> st;
  //cout<<"Finding for "<<curr<<"\n";
  st.push({curr,0});
  while(!st.empty()){
    int c = st.top().first;
    ll cd = st.top().second;
    //cout<<"Current Node visiting: "<<c<<" dist "<<cd<<"\n";
    if(cd >= dist[curr][c]){
      //cout<<"Already smaller route exists\n";
      st.pop();
      continue;
    }
    dist[curr][c] = cd;
    st.pop();
    //cout<<"Updated distance: "<<dist[curr][c]<<"\n";
    for(auto v : vec[c]) {
      ll w = v.second;
      int i = v.first;
      
      if(w + cd < dist[curr][i]) {
        //cout<<"Pushing: "<<i<<"distance: "<<w + cd<<"\n";
        if(!st.empty())
          minStackPush(st,i,w+cd);
        else st.push({i,w+cd});
      }
    }
  }
}

void floydW(vector<vector<ll>> &dist){
  for(int i = 0; i < dist.size(); i++){
    for(int j = 0; j < dist.size();j++){
      for(int k = 0; k < dist.size(); k++){
        if(dist[j][i] != LLONG_MAX && dist[i][k] != LLONG_MAX)
          dist[j][k] = min(dist[j][i]+dist[i][k],dist[j][k]);
      }
    }
  }
}

int main() {
  int n,m,q;
  cin>>n>>m>>q;
  vector<vector<pair<int,ll>>> vec(n);
  ll x;
  int a,b;
  //for(int i = 0; i < m; i++){
  //  cin>>a>>b>>x;
  //  vec[a-1].push_back({b-1,x});
  //  vec[b-1].push_back({a-1,x});
  //}
  vector<vector<ll>> dist(n,vector<ll>(n,LLONG_MAX));
  for(int i = 0, j = 0; i < n && j < n; i++, j++) {
    // cout<<i<<" "<<j<<endl;
    dist[i][j] = 0; 
  }
  for(int i = 0; i < m; i++){
    cin>>a>>b>>x;
    if(dist[a-1][b-1]>x){
    dist[a-1][b-1] = x;
    dist[b-1][a-1] = x;}
  }
  floydW(dist);
  // for(int i = 0; i < n; i++){
  //   solve(vec,dist,i);
  // } 
  for(int i = 0; i < q; i++){
    cin>>a>>b;
    cout<<(dist[a-1][b-1]==LLONG_MAX?-1:dist[a-1][b-1])<<"\n";
  }
  return 0;
}