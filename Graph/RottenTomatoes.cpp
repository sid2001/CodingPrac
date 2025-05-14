//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    
    void bfs(vector<vector<int>>& grid, vector<vector<int>> &visited, queue<vector<int>> &q, int &tim,int &fr){
        
        
        while(!q.empty()){
            
            
            int cx = ((q.front()))[0];
            int cy = ((q.front()))[1];
            int ct = ((q.front()))[2];
            q.pop();
            visited[cx][cy] = 2;
            // cout<<ct<<endl;
            tim = max(tim,ct);
            
            for(int i = 0;i<4;i++){
                int x = cx+dx[i];
                int y = cy+dy[i];
                if(x>-1&&x<grid.size()&&y>-1&&y<grid[0].size()){
                    if(visited[x][y]==0&&grid[x][y]==1){
                        // cout<<x<<" "<<y<<endl;
                        // cout<<ct<<endl;
                        vector<int> vec{x,y,ct+1};
                        q.push(vec);
                        visited[x][y] = 1;
                        fr--;
                    }
                }
            }
            
        }
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<vector<int>> q;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int tim = 0;
        int fr = 0;
        for(int i = 0;i<grid.size();i++){
            
            for(int j = 0; j <grid[i].size();j++){
                if(grid[i][j]==1) fr++;
                if(visited[i][j]==0&&grid[i][j]==2){
                    vector<int> vec{i,j,0};
                    q.push(vec);
                    visited[i][j] = 2;
                }
            }
        }
        
        
        bfs(grid,visited,q,tim,fr);
        if(fr>0) return -1;
        return tim;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends