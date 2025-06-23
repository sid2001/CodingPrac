#include <iostream>
#include <vector>
using namespace std;

int travel(vector<int> &earn, vector<vector<int>> &adj, int c,int &trips,int trip, int u_earned = 0,int curr = 0, int curr_trips = 0, int curr_earning = 0,bool flag = 0) {
   if(trips > 1000) return -1;
    if(curr == 0 && flag) return (curr_earning - curr_trips*curr_trips*c); 

   int earned  = 0;  
    for(int i = 0; i < adj[curr].size();i++ ){
        earned = max(earned, travel(earn, adj,c, trips, u_earned, adj[curr][i], curr_trips+1, curr_earning + earn[adj[curr][i]],1));
    } 
    return earned;
}

int solve(vector<int> &earn, vector<vector<int>> &adj, int c) {
    int earned = 0,x,trips = 0;
    do {
        x = travel(earn,adj,c,trips);
        earned += x;
    }while(x);

    return earned;
    
}

int main() {
    int m,n,c,a,b;
    cin>>n>>m>>c;
    vector<int> earn(n);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) cin>>earn[i];
    for(int i = 0; i < m; i++) {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }

    cout<<solve(earn, adj, c);
}
