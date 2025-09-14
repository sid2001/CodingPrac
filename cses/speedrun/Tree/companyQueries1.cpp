#include <iostream>
#include <vector>

using namespace std;

int LOG = 0;

void preprocessLCA(vector<vector<int>>& ancest, vector<vector<int>>& nodes) {
    // for(int i = 0; i < ancest.size(); i++) ancest[i][0] = nodes[i][0]; // mark immediate ancestor

    for(int i = 0; i < (int)ancest.size(); i++) {
        ancest[i][0] = nodes[i][0];
        nodes[i][1] = nodes[nodes[i][0]][1] + 1;
        for(int j = 1; j < LOG; j++) { // this only works if parent[i] < i; for it work for any order then just swap the loop sequence
            ancest[i][j] = ancest[ancest[i][j-1]][j-1];
        }
    }
}

int main() {
    int n, q, x,a,b;
    cin>>n>>q;
    vector<vector<int>> nodes(n, {0,0}); // {parent, depth}
    while(1 << LOG <= n) LOG++;
    vector<vector<int>> ancest(n, vector<int>(LOG));
    for(int i = 1; i < n; i++) {
        cin>>x;
        x--;
        nodes[i][0] = x;
    }

    preprocessLCA(ancest, nodes);
    while(q--) {
        cin>>a>>b;
        a--;
        if(nodes[a][1] <= b) cout<<-1<<"\n";
        else {
            for(int i = 20; i >= 0; i--) {
                if(b & 1<<i) {
                    a = ancest[a][i];
                }
            }
            cout<<a+1<<"\n";
        }
    }
    return 0;
}