#include <iostream>
#include <vector>

using namespace std;

int LOG = 0;

void dfs(vector<vector<int>>& adj, vector<vector<int>>& ancest,vector<vector<int>>& nodes, int curr, int& time, int dist, int p) {
    // ancest[curr][0] = nodes[curr][0];  
    nodes[curr][1] = time++;
    nodes[curr][3] = dist;
    for(int child : adj[curr]) {
        if(child == p) continue;
        ancest[child][0] = curr;
        for(int j = 1; j < LOG; j++) {
            ancest[child][j] = ancest[ancest[child][j-1]][j-1];
        }
        dfs(adj, ancest, nodes, child, time, dist+1, curr);
    }
    nodes[curr][2] = time++;
}

bool is_ancestor(int in_a, int out_a, int in_b, int out_b) {
    return in_a < in_b && out_a > out_b;
}

int main() {
    int n, q, x, a, b;
    cin>>n>>q;
    while(1 << LOG <= n)  LOG++;
    vector<vector<int>> ancest(n,vector<int>(LOG));
    vector<vector<int>> adj(n);
    vector<vector<int>> nodes(n, {0,0,0,0}); // {parent, in_time, out_time,dist}

    for(int i = 1; i < n; i++) {
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int time = 0;
    dfs(adj, ancest, nodes, 0, time, 0, 0);

    while(q--) {
        cin>>a>>b;
        a--; b--;
        int aa = a, bb = b;
        if(a == b) {
            cout<<0<<"\n";
            continue;
        }
        if(a == 0 || b == 0) {
            cout<<max(nodes[a][3],nodes[b][3])<<"\n";
            continue;
        }
        if(is_ancestor(nodes[a][1], nodes[a][2], nodes[b][1], nodes[b][2])) cout<<nodes[b][3] - nodes[a][3]<<"\n";
        else if(is_ancestor(nodes[b][1], nodes[b][2], nodes[a][1], nodes[a][2])) cout<<nodes[a][3] - nodes[b][3]<<"\n";
        else {

            for(int i = LOG - 1; i >= 0; i--) {
                if(!is_ancestor(nodes[ancest[a][i]][1], nodes[ancest[a][i]][2], nodes[b][1], nodes[b][2])) a = ancest[a][i];

            }
            cout<<nodes[aa][3] + nodes[bb][3] - 2 * nodes[ancest[a][0]][3]<<"\n";
        }
    }
    return 0;
}