#include <iostream>
#include <vector>

using namespace std;

int main() {
	int mod = 1e9 + 7;
	int n,m;
	cin>>n>>m;
	vector<int> vec(n);
	vector<pair<int,int>> tb(n);

	for(int i = 0;i < n; i++) cin >> vec[i];
	
	int ub = m, lb = 1;
	for(int i = 0; i < n; i++) {
		if(!vec[i]) {
			tb[i] = {lb, ub};
			if(lb > 1) lb--;
			if(ub < m) ub++;
		} else if(!(vec[i] >= lb && vec[i] <= ub)) {
		    cout<<0<<"\n";
		    return 0;
		} 
		else {
			tb[i] = {vec[i],vec[i]};
			if(vec[i] > 1) lb = vec[i] - 1;
			else lb = 1;
			if(vec[i] < m) ub = vec[i] + 1;
			else ub = m;
		}
	}
	ub = m, lb = 1;
	for(int i = n - 1; i >= 0; i--) {
		if(!vec[i]) {
			tb[i] = {max(lb,tb[i].first), min(ub, tb[i].second)};
			if(lb > 1) lb--;
			if(ub < m) ub++;
		} else {
			tb[i] = {vec[i],vec[i]};
			if(vec[i] > 1) lb = vec[i] - 1;
			else lb = 1;
			if(vec[i] < m) ub = vec[i] + 1;
			else ub = m;
		}
	}
    // for(auto v: tb) {
    //     cout<<"("<<v.first<<" "<<v.second<<") ";
    // }
    // cout<<endl;
	int ans = 0;
	vector<vector<int>> dp(n,vector<int>(m+1, 0));
	for(int i = tb[0].first; i < tb[0].second + 1; i++) {
		dp[0][i] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = tb[i].first; j < tb[i].second + 1; j++) {
			if(j-1 >= tb[i-1].first && j-1 <= tb[i-1].second) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
			}
			if(j >= tb[i-1].first && j <= tb[i-1].second) {
				dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
			}
			if(j + 1 >= tb[i-1].first && j + 1 <= tb[i-1].second) {
				dp[i][j] = (dp[i][j] + dp[i-1][j + 1])%mod;
			}
		}
	}
// 	for(auto d: dp[n-1]) cout<<d<<" ";
// 	cout<<endl;
	for(auto v : dp[n-1]) ans = (ans + v)%mod;
	cout<<ans<<"\n";
	return 0;
}
