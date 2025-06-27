#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,x;
	int INF = 1e9+1;
	int ans = 1;
	cin>>n;
	vector<int> dp(n + 1, INF);
	dp[0] = -INF;
	for(int i = 0; i < n; i++) {
		cin>>x;
		auto it = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
		if(dp[it - 1] < x && x < dp[it])
			dp[it] = x;
	}
	for(int i = 1; i < n+1; i++) {
		if(dp[i] < INF) ans = i;
	}
	cout<<ans<<"\n";
}
