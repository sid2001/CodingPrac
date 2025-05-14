//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void bfs(vector<int> adj[],vector<int> &visited, int curr,bool &cycle){
        
        queue<int> q;
        q.push(curr);
        visited[curr] = curr;
        while(!q.empty()){
            
            int visiting = q.front();
            q.pop();
            for(int i:adj[visiting]){
                
                if(visited[i]==-1){
                    visited[i] = visiting;
                    q.push(i);
                }
                else if(visited[visiting]==i){
                    continue;
                }
                else{
                    cycle = true;
                    return;
                }
            }
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,-1);
        bool cycle = false;
        for(int i  = 0;i<V;i++){
            if(visited[i]==-1){
                bfs(adj,visited,i,cycle);
            }
            if(cycle) break;
        }
        return cycle;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends