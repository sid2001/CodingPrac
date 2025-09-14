#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solve(vector<vector<int>> &vec,unordered_set<int>& st, vector<int>& ans, int curr, int parent) {
	int flag = 0;
	for(int nei : vec[curr]) {
		if(nei != parent) {
			ans += solve(vec, st, ans, nei, curr);
		}
	}
}

int main() {
	int n,a,b;
	cin>>n;
	vector<int> color(n,0);
	vector<vector<int>> vec(n);
	unordered_set<int> st;
	vector<int> ans(n, 0);
	for(int i = 0; i < n; i++) cin>>color[i];
	for(int i = 0; i < n - 1; i++) {
		cin>>a>>b;
		vec[a-1].push_back(b - 1);
		vec[b-1].push_back(a - 1);
	}
	
}
