#include <iostream>
#include <vector>

using namespace std;

int LOG = 0;

void dfs(vector<vector<int>>& adj, vector<vector<int>>& ancest,vector<vector<int>>& nodes, int curr, int& time) {
    // ancest[curr][0] = nodes[curr][0];
    
    
    nodes[curr][1] = time++;
    for(int child : adj[curr]) {
        ancest[child][0] = curr;
        for(int j = 1; j < LOG; j++) {
            ancest[child][j] = ancest[ancest[child][j-1]][j-1];
        }
        dfs(adj, ancest, nodes, child, time);
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
    vector<vector<int>> nodes(n, {0,0,0}); // {parent, in_time, out_time}

    for(int i = 1; i < n; i++) {
        cin>>x;
        x--;
        nodes[i][0] = x;
        adj[x].push_back(i);
    }
    int time = 0;
    dfs(adj, ancest, nodes, 0, time);

    while(q--) {
        cin>>a>>b;
        a--; b--;
        if(a == b) {
            cout<<a+1<<"\n";
            continue;
        }
        x  = 1;
        if(is_ancestor(nodes[a][1], nodes[a][2], nodes[b][1], nodes[b][2])) cout<<a+1<<"\n";
        else if(is_ancestor(nodes[b][1], nodes[b][2], nodes[a][1], nodes[a][2])) cout<<b+1<<"\n";
        else {

            for(int i = LOG - 1; i >= 0; i--) {
                if(!is_ancestor(nodes[ancest[a][i]][1], nodes[ancest[a][i]][2], nodes[b][1], nodes[b][2])) a = ancest[a][i];

            }
            cout<<ancest[a][0] + 1<<endl;
        }
    }
    return 0;
}