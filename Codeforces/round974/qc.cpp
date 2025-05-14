#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
  int n;
  cin>>n;
  vector<double> v(n,0);
  double m_a = -1;
  double tot = 0;
  for(int i = 0;i<n;i++) {
    cin>>v[i];
    tot += v[i];
    m_a = max(m_a,v[i]);
  }
  if(n<3) {
    cout<< -1 <<"\n";
    return;
  }
  sort(v.begin(),v.end());
  int mid = n/2 + 1;
  //while(v[mid-1] == v[mid] && mid < n) mid++;
  double avg = tot/(n*2.0);
  if(v[mid-1] < avg) {
    //if(mid==n && m_a==v[mid-1]) cout<< -1 <<"\n";
    cout<<0<<"\n";
    return;
  }
  double x = v[mid-1] *n* 2 - tot;
  if(x<0) {
    cout<< 0 <<"\n";
  } else {
    x = ceil(x);
    while((x+tot)/(n*2.0)<=v[mid-1]) x++;
    cout<<(long long)x<<"\n";
  }
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}