class Solution {
    private:
        int time = 1;
    private:
        void DFS(int parent,vector<int> adj[],int curr,int n,vector<vector<int>> &bridge,int visited[],int low[],int inse[]){

            visited[curr] = 1;
            low[curr] = time;
            inse[curr] = time;
            time++;
            for(auto i : adj[curr]){
                    if(parent == i) continue;
                    else if(visited[i]) {
                        low[curr] = min(low[i],low[curr]);
                    }
                    else{

                        DFS(curr,adj,i,n,bridge,visited,low,inse);
                        low[curr] = min(low[curr],low[i]);
                        if(inse[curr]<low[i])
                            bridge.push_back({curr,i});
                    }
            }
        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];

        for(auto it:connections){

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridge;
        int visited[100000] = {0};
        int low[100000] = {-1};
        int inse[100000] = {-1};
        DFS(-1,adj,0,n,bridge,visited,low,inse);
        return bridge;
    }
};