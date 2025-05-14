#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
  
  long long t;
  cin>>t;
  while(t--) {
    long long n;
    cin>>n;
    vector<long long> pre(n,0);
    cin>>pre[0];
    for(long long i = 1;i < n; i++) {
      long long x;
      cin>>x;
      pre[i] = x + pre[i-1];
    }
    string st;
    cin>>st;
    long long l = 0, r = n-1;
    vector<pair<long long,int>> v;
    while(l<r) {
      while(l<n && st[l]!='L') l++;
      while(r >= 0 &&st[r] != 'R') r--;
      if(l>=r) break;
      v.push_back({l,r});
      l++;
      r--;
    }
    long long sum = 0;
    for(auto i:v) {
      if(i.first == 0) {
        sum += pre[i.second];
      } else {
        sum += pre[i.second] - pre[i.first-1];
      }
    }
    cout<<sum<<"\n";
  }
  return 0;
}