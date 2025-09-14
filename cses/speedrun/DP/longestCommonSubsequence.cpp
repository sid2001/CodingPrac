#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    vector<int> s1(n), s2(m), s;
    for(int i = 0; i < n; i++) cin>>s1[i];
    for(int j = 0; j < m; j++) cin>>s2[j];
    vector<vector<int>> dir(n,vector<int>(m, -1));
    auto solve = [&]() {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    if(dp[i - 1][j - 1] + 1 > dp[i-1][j]) dir[i-1][j-1] = 2;
                    else dir[i - 1][j - 1] = 1;
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i-1][j]);
                }else{
                    if(dp[i][j - 1] > dp[i-1][j]) dir[i-1][j-1] = 0;
                    else dir[i - 1][j - 1] = 1;
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    };

    cout<<solve()<<"\n";
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0) {
        if(dir[i][j] == 2) {
            s.push_back(s1[i]);
            i--;j--;
        }else if(dir[i][j] == 1) {
            i--;
        }else j--;
    }
    for(int i = s.size() - 1; i >= 0; i--) {
        cout<<s[i]<<" ";
    }
    return 0;
}
