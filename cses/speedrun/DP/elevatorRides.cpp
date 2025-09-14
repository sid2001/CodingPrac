#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n, x;
	cin>>n>>x;
	int ans = 0;
	vector<int> vec(n);
	int mask = 1<<n;
	vector<pair<int,int>> dp(pow(2,n), {21, x});
	for(int i = 0; i < n; i++) {
		cin>>vec[i];
	}
	dp[0]= {1, 0};
	for(int i = 1; i < mask; i++) {
		for(int j = 0; j < n; j++) {
			if(i & (1<<j)) {
				int weight = dp[i^(1<<j)].second;
				if(weight + vec[j] <= x) {
					dp[i] = min(dp[i], {dp[i^(1<<j)].first, weight + vec[j]});
				}else{
					dp[i] = min(dp[i], {1 + dp[i^(1<<j)].first, vec[j]});
				}
			}
		}
	}
	
	cout<<dp[mask - 1].first<<"\n";
}
