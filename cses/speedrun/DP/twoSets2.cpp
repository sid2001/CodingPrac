#include <iostream>
#include <vector>
#define ull long long

using namespace std;

int mod = 1e9 + 7;

int solve(vector<vector<ull>> &dp,ull curr, ull upper, ull target) {
	if(target == 0) return 1;
    if(curr > upper) return 0;
	if(dp[target][curr] != -1) return dp[target][curr];
	ull left = 0, right = 0;
	if(curr <= upper && curr <= target)
		left = solve(dp, curr + 1, upper, target - curr);
	if(curr <= upper)
	    right = solve(dp, curr + 1, upper, target);
	dp[target][curr] = (left + right) % mod;
	return dp[target][curr];
} 

int main() {

	ull n;
	cin>>n;
	ull s = (n*(n + 1))/2;
	if(s%2) {
		cout<<0<<"\n";
		return 0;
	}
	s /= 2;
	vector<vector<ull>> dp(s + 1,vector<ull>(n+1,-1));
	solve(dp, 1, n,s);
	cout<<dp[s][2]<<"\n";
	
}
