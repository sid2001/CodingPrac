// wrong output
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, x;
	cin>>n>>x;
	int ans = 0;
	vector<int> vec(n);
	vector<int> visited(n, 0);
	for(int i = 0; i < n; i++) cin>>vec[i];
	for(int i = 0; i < n;) {
		if(!visited[i]) {
			vector<vector<int>> dp;
			for(int j = i; j < n; j++) {
				if(visited[j]) continue;
				vector<int> mx = {0,-1,-1};
				for(int k = 0; k < dp.size();k++) {
					if(x - dp[k][0] >= vec[j]) {
						if(mx[0] < dp[k][0]) {
							mx[0] = dp[k][0];
							mx[1] = k;
						}
					}
				}
				dp.push_back({mx[0] + vec[j], mx[1], j});
			}
			int d = 0;
			for(int j = 0; j < dp.size(); j++) {
				if(dp[j][0] > dp[d][0]) d = j;
			}
			while( d != -1) {
				visited[dp[d][2]] = 1;
				// cout<<vec[dp[d][2]]<<" ";
				d = dp[d][1];
			}
			ans++;
// 			cout<<endl;
			while(visited[i]) i++;
		}
	}
	cout<<ans<<"\n";
}
