#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.

    vector<int> dfsOfGraph(int V, vector<int> adj[],int curr = 0) {
        // Code here
        static vector<int> visited(V,0);
        static vector<int> nv = {0};
        visited[curr] = 1;
        for(int i = 0; i<adj[curr].size();i++){
            
            if(!visited[adj[curr][i]]){
                nv.push_back(adj[curr][i]);
                dfsOfGraph(V,adj,adj[curr][i]);
            }
        }
        return nv;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} 