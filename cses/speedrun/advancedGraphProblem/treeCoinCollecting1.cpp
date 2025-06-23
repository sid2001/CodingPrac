#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n,q,a,b;
	cin>>n>>q;
	vector<int> nodes(n);
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++) cin>>nodes[i];
	for(int i = 0; i < n - 1; i++) {
		cin>>a>>b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < q; i++) {
		cin>>a>>b;
		a--;b--;
		
	}
}
