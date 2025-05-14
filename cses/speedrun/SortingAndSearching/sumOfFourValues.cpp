#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

int main() {
  int n;
  ll x;
  cin>>n>>x;
  ll a;
  vector<pair<ll,int>> vec(n);
  for(int i = 0; i < n; i++) {
    cin >> a;
    vec[i] = {a,i};
  }
  sort(vec.begin(),vec.end());
  vector<pair<int, int>> right;
  vector<pair<int,int>> left;
  for(int i = 0; i < n-1; i++) {
    if(vec[i].first + vec[i].first > x/2) break;
    for(int j = i+1; j < n; j++) {
      if(vec[i].first + vec[j].first <= x/2){
        left.push_back({i,j});
      }
    }
  }
  for(int i = n-1; i > 0; i--) {
    if(vec[i].first + vec[i].first < x/2) break;
    for(int j = i-1; j >= 0; j--){
      if(vec[i].first + vec[j].first >= x/2) right.push_back({j,i});
    }
  }
  int flag = 0;
  auto cmp = [&](const pair<int,int> a, const pair<int,int> b){return a.first < b.first; };

  sort(left.begin(),left.end());
  sort(right.begin(),right.begin(),cmp);
  for(int i = 0; i<left.size();i++) {
    for(int j = 0; j < right.size(); j++) {
      if(left[i].second >= right[j].first) break;
      // if(left[i].second >= right[j].first) continue;
      if(vec[left[i].first].first + vec[left[i].second].first + vec[right[j].first].first + vec[right[j].second].first == x) {
        // cout<<vec[left[i].first] + vec[left[i].second] + vec[right[j].first] + vec[right[j].second]<<endl;
        flag = 1;
        cout<<vec[left[i].first].second+1<<" "<<vec[left[i].second].second+1<<" "<<vec[right[j].first].second+1<<" "<<vec[right[j].second].second+1<<"\n";
        break;
      }
    }
    if(flag) break;
  }

  if(!flag) cout<<"IMPOSSIBLE"<<endl;
}
