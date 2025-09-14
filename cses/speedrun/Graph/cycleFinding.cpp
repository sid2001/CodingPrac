#include <iostream>
#include <vector>
#include <limits.h>
#define ll long long
using namespace std;

bool flag = true;
bool f = false;
void dfs(vector<vector<vector<ll>>>& adj, vector<ll>& visited, ll curr, ll wei, int till){

  if(visited[curr] != LLONG_MIN && wei - visited[curr]  < 0) {
    flag = false;
    f = true;
    till = curr;
    cout << "YES" <<"\n";
    cout << curr + 1 << " ";
    return;
  }
  if(visited[curr] != LLONG_MIN) return;
  visited[curr] = wei;
  for(vector<ll>& nei : adj[curr]) {
    dfs(adj, visited, nei[0], wei + nei[1], till);
    if(f) {
      cout << curr + 1 << " ";
      if(till == curr) {
        f = false;
      }
      return;
    }
    if(!flag) return;
  }
  visited[curr] = LLONG_MIN;
  return;
}

int main() {
  int n,m;
  cin>>n>>m;
  ll a, b, c;
  vector<vector<vector<ll>>> adj(n);
  for(int i = 0;i < m; i++) {
    cin>>a>>b>>c;
    adj[a - 1].push_back({b-1, c});
  }
  vector<ll> visited(n, LLONG_MIN);
  dfs(adj, visited, 0, 0, -1);
  if(flag) cout<<"NO"<<endl;
  return 0;
}