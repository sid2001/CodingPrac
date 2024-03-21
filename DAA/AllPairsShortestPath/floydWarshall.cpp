#include<bits/stdc++.h>
using namespace std;
//here -1 means infinity
#define INF 2000
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int i = 0;i<matrix.size();i++){
	            for(int j = 0;j<matrix.size();j++){
	                matrix[i][j] = matrix[i][j]==-1?INF:matrix[i][j];
	            }
	    }
	    
	    
	    for(int k = 0;k<matrix.size();k++){
	        for(int i = 0;i<matrix.size();i++){
	            for(int j = 0;j<matrix.size();j++){
	                if(i!=k&&j!=k){
	                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                }
	            }
	        }
	    }
	    for(int i = 0;i<matrix.size();i++){
	            for(int j = 0;j<matrix.size();j++){
	                matrix[i][j] = matrix[i][j]==INF?-1:matrix[i][j];
	            }
	    }
	}
	
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
