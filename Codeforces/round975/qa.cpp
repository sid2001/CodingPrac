#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
  int n;
  cin>>n;
  vector<int> vec(n);
  int o_max = -1, e_max = -1;
  for(int i = 0; i<n;i++) {
    cin>>vec[i];
    if(i%2 != 0) {
      o_max = max(o_max,vec[i]);
    } else {
      e_max = max(e_max,vec[i]);
    }
  }
  int odd_sum,even_sum = 0;
  even_sum = e_max + (n%2!=0 ? n/2 + 1 : n/2);
  odd_sum  = o_max + n/2;
  cout<<max(even_sum,odd_sum)<<"\n";
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}