#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
	return (a.first.second < b.first.second);
}

int main() {
	int n;
	int a, b, x;
	int INF = 1e5 + 1;
	vector<int> ans(n+1,INF);
	ans[0] = 
	vector<int> start(n,-1);
	vector<int> end(n,-1);
	vector<pair<pair<int,int>,int>> vec;
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin >> a >>b>>x;
		vec.push_back({{a,b},x});
	}
	sort(vec.begin(), vec.end(), comp);
	for(int i = 0;i < n; i++) {
		auto it = 
	}
}
