#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin>>vec[i];
  }
  int s;
  for(int i = 0; i < n-1; i++) {
    s = abs(vec[i] - vec[i+1]);
    if(s!=7&&s!=5){
      cout<<"NO"<<"\n";
      return;
    }
  }
  cout<<"YES"<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}