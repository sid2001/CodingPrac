#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void path(vector<int> &visited,int stop, int start,int x) {
  int count = 1;
  vector<int> vec;
  string ans = "";
  vec.push_back(x);
  while(true) {
    count++;
    vec.push_back(start);
    if(start == stop) {
      vec.push_back(x);
      count++;
      break;
    }
    start = visited[start];
  }
  cout<<count<<"\n";
  for(auto a:vec){
    cout<<a<<" ";
  }
  cout<<flush;
  return;
}

int dfs(vector<vector<int>> &vec, vector<int> &visited,int curr) {
  stack<int> st;
  st.push(curr);
  visited[curr] = curr;
  int stop = curr;
  while(!st.empty()) {
    int x = st.top();
    st.pop();
    for(auto v : vec[x]) {
      if(!visited[v]) {
        visited[v] = x;
        st.push(v);
      }else if(v!=visited[x]){
        stop = visited[v];
        path(visited, stop, x,v);
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vec(n+1);
  int a,b;
  for(int i = 0; i < m; i++) {
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  vector<int> visited(n+1,0);
  int aa = 0;
  for(int i = 1;i <= n; i++) {
    if(!visited[i]) aa = dfs(vec, visited,i);
    if(aa) break;
  }
  if(!aa) cout<<"IMPOSSIBLE"<<endl;

  return 0;
}