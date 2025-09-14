#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        vec[i] = {x, i};
    }

    sort(vec.begin(), vec.end(), compare);

    int ans = 1;
    // int prev = 0;
    for(int i = 0; i < n - 1; i++) {
        if(vec[i][1] > vec[i+1][1]) ans++;
    }
    for(int i = 0; i < n; i++) {
        dp[vec[i][1]] = i;
    }
    int a, b;
    while(m--) {
        cin>>a>>b;
        a--; b--;
        int aa = a;
        int bb = b;

        a = dp[a];
        b = dp[b];

        
        if(a < n - 1 && vec[a][1] > vec[a+1][1]) ans--;
        if(a > 0 && vec[a - 1][1] > vec[a][1]) ans--;
        if(b < n - 1 && vec[b][1] > vec[b+1][1]) ans--;
        if(b > 0 && vec[b - 1][1] > vec[b][1]) ans--;
        
        int t = vec[a][1];
        vec[a][1] = vec[b][1];
        vec[b][1] = t;
        dp[aa] = a;
        dp[bb] = b;

        if(a < n - 1 && vec[a][1] > vec[a+1][1]) ans++;
        if(a > 0 && vec[a - 1][1] > vec[a][1]) ans++;
        if(b < n - 1 && vec[b][1] > vec[b+1][1]) ans++;
        if(b > 0 && vec[b - 1][1] > vec[b][1]) ans++;;

        cout<<ans<<"\n";
    }
    return 0;
}