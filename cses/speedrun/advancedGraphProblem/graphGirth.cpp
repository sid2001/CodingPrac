#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(vector<vector<int>> &adj, pair<int,int> edge, int &ans) {
	vector<int> visited(adj.size(),0);
	queue<pair<int,int>> q;
	q.push({edge.first,1});
	while(!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		if(curr == edge.second) {
			ans = min(ans, dist);
			return;
		}
		if(dist >= ans) return;
		q.pop();
		for(auto nei: adj[curr]) {
			if((curr == edge.first && nei == edge.second) || (curr == edge.second && nei == edge.first)) continue;
			if(!visited[nei]) {
				visited[nei] = 1;
				q.push({nei,dist+1});
			}
		}
	}
}

int main() {
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>> adj(n);
	vector<pair<int,int>> edges;
	for(int i = 0; i < m; i++) {
		cin>>a>>b;
		a--;
		b--;
		edges.push_back({a,b});
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = n+1;
	for(auto v: edges) {
    	solve(adj,v,ans);
	}
// 	cout<<ans<<endl;
	cout<<((ans == n + 1)?-1:ans);
}
