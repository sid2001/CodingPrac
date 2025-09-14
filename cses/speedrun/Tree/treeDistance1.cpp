#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& vec, int curr, int dist, int parent) {
  int ans = dist;
  for(int nei: vec[curr]) {
	if(nei != parent) {
	  ans = max(ans, dfs(vec, nei, dist + 1, curr));
	}
  }
  return ans;
}

void travel(vector<vector<int>>& vec, vector<int>& ans, int curr, int dist, int parent) {
  ans[curr] = dist;
  for(int nei : vec[curr]){
	if(nei != parent) {
	  travel(vec, ans, nei, dist + 1, curr);
	}
  }

  return;
}

int main() {
  int n,a,b;
  cin>>n;
  vector<vector<int>> vec(n);
  vector<int> deg(n, 0);
  for(int i = 0; i < n-1; i++) {
    cin>>a>>b;
    vec[a-1].push_back(b-1);
    vec[b-1].push_back(a-1);
	deg[a-1]++;
	deg[b-1]++;
  }
  if(n == 1) {
	cout<<0<<endl;
	return 0;
  }
  vector<int> dead(n,0);
  queue<int> leaves;
  for(int i = 0; i < n; i++) {
	if(deg[i] == 1) {
	  dead[i] = 1;
	  leaves.push(i);
	}
  }
  int center = 0;
  while(!leaves.empty()) {
	int curr = leaves.front();
	center = curr;
	leaves.pop();
	for(int nei: vec[curr]) {
	  if(!dead[nei]) {
		deg[nei]--;
		if(deg[nei] == 1) {
		  leaves.push(nei);
		  dead[nei] = 1;
		}
	  }
	}
  }
  int cd = vec[center].size();
  vector<int> tb(cd,0);
  vector<int> ans(vec.size(), 0);
  int ma = 0;
  for(int i = 0; i < cd; i++) {
	tb[i] = dfs(vec, vec[center][i], 1, center);
	if(tb[ma] < tb[i]) ma = i;
  }
  int ma2 = 0;
  for(int i = 0; i < cd; i++) {
	if(ma != i) {
	  ma2 = max(tb[i], ma2);
	}
	tb[i] = tb[ma];
  }
  ans[center] = tb[ma];
  tb[ma] = ma2;
  for(int i = 0; i < cd; i++) {
	travel(vec, ans, vec[center][i], tb[i] + 1, center);
  }
  for(int i : ans) cout<<i<<" ";
  cout<<endl;
  return 0;
}
