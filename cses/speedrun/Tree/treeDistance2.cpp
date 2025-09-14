#include <iostream>
#include <vector>

using namespace std;

vector<long long> collect(vector<vector<vector<long long>>>& adj, vector<vector<long long>>& dp, long long curr, long long parent) {

    long long t_sum  = 0;
    long long t_node = 1;
    for(vector<long long>& child : adj[curr]) {
        if(child[0] == parent) continue;
        vector<long long> val = collect(adj,dp, child[0], curr);
        // adj[curr][child[0]][1] = val[0];
        child[1] = val[0] + val[1];
        child[2] = val[1];
        // adj[curr][child[0]][2] = val[1];
        t_sum = t_sum + val[0] + val[1];
        t_node = t_node + val[1];
    }
    dp[curr] = {t_sum, t_node};
    return {t_sum, t_node};
}

void distribute(vector<vector<vector<long long>>>& adj, vector<vector<long long>>& dp, long long curr, long long parent, vector<long long> dat) {
    dp[curr] = {dp[curr][0] + dat[0] + dat[1], dp[curr][1] + dat[1]};
    for(vector<long long>& child : adj[curr]) {
        if(child[0] == parent) continue;
        distribute(adj, dp, child[0], curr, {dp[curr][0] - child[1],dp[curr][1] - child[2]});
    }
}

int main() {
    long long n,a,b;
    cin>>n;
    vector<vector<vector<long long>>> adj(n); // {node, sum, number}
    for(long long i = 0; i < n - 1; i++) {
        cin>>a>>b;
        adj[a - 1].push_back({b - 1, 0, 0});
        adj[b - 1].push_back({a - 1, 0, 0});
    }
    vector<vector<long long>> dp(n);  
    collect(adj, dp, 0, 0);
    for(vector<long long>& child : adj[0]) {
        distribute(adj, dp, child[0], 0, {dp[0][0] - child[1],dp[0][1] - child[2]});
    }

    for(auto v : dp) cout<<v[0]<<" ";
    cout<<endl;
    return 0;
}