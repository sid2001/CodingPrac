#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> seen;

void dfs(vector<vector<pair<int,int>>> &adj, vector<int> &ans,int curr = 0) {
	while(!adj[curr].empty()){
		auto [node, edge] = adj[curr].back();
		adj[curr].pop_back();
		if(seen[edge]) continue;
		seen[edge] = 1;
		dfs(adj, ans, node);
	}
	ans.push_back(curr + 1);
}

int main() {
	int n, e, a, b;
	cin>>n>>e;
	vector<vector<pair<int,int>>> adj(n);
	vector<int> ans;
	vector<int> deg(n, 0);
	seen.resize(e);

	for(int i = 0; i < e; i++) {
		cin>>a>>b;
		adj[a-1].push_back({b-1, i});
		adj[b-1].push_back({a-1, i});
		deg[a-1]++;
		deg[b-1]++;
	}
	
	for(int i = 0; i < deg.size(); i++) {
		if(deg[i] % 2) {
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	}

	dfs(adj, ans);
	
	if(ans.size() != e + 1) cout<<"IMPOSSIBLE";
	else for(auto v: ans) cout<<v<<" ";
	cout<<endl;
	return 0;
}
