#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

void solve(vector<vector<ll>> &adj, vector<pair<ll,ll>> &visited, ll* time, ll curr ) {
	visited[curr].second = curr;

	for(auto nei: adj[curr]) {
		if(visited[nei].second == -1) {
			solve(adj, visited, time, nei);
		}
	} 
	*time = *time - 1;
	visited[curr].first = *time;
}

ll comp(vector<vector<ll>> &adj, vector<ll> &visited, vector<ll> &coins, ll curr, ll region) {
	visited[curr] = region;
	ll ans = coins[curr];
	for(auto nei: adj[curr]) {
		if(!visited[nei]) {
			ans += comp(adj, visited, coins, nei,region);
		}
	} 
	return ans;
}

ll fin(vector<vector<int>> &adj, vector<ll> &coins, vector<ll> &tb, ll curr) {
	if(tb[curr] != -1) return tb[curr];
	ll ans =  0;
	for(auto nei: adj[curr]) {
		ans = max(ans, fin(adj, coins, tb, nei));
	}
	return ans + coins[curr];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n,m,a,b;
	cin>>n>>m;
	vector<ll> coins(n);
	vector<vector<ll>> adj(n);
	vector<vector<ll>> rev(n);
	for(ll i = 0; i < n; i++) cin>>coins[i];
	for(ll i = 0; i < m; i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		rev[b-1].push_back(a-1);
	}

	vector<pair<ll,ll>> visited(n,{0,-1});
	ll time = -1; 
	for(ll i = 0; i < n; i++) {
		if(visited[i].second == -1) {
			solve(adj, visited, &time,i);
		}
	}
	sort(visited.begin(), visited.end());
	vector<ll> vis(n,0);
	vector<ll> comp_sum;
	for(ll i = 0; i < n; i++) {
		ll c;
		if(!vis[visited[i].second]) {
			comp_sum.push_back(comp(rev, vis, coins, visited[i].second, comp_sum.size() + 1));
		}
	}
	vector<vector<int>> condensed_adj(comp_sum.size());
	vector<ll> v(n,0);
	for(ll i = 0; i < n; i++) {
		ll u_s = vis[i] - 1;
		for(auto nei: adj[i]) {
			ll v_s = vis[nei] - 1;
			if(v_s != u_s) condensed_adj[u_s].push_back(v_s);
		}
	}
	vector<ll> tb(comp_sum.size(), -1);
	ll ans = 0;
	for(ll i = 0;i < comp_sum.size(); i++) {
		if(tb[i] == -1) {
			ans = max(ans, fin(condensed_adj,comp_sum,tb, i));
		}
	}
	cout<<ans<<"\n";
}
