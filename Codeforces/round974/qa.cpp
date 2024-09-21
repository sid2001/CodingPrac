#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n,k;
  cin>>n>>k;
  int mon = 0;
  int ans = 0;
  for(int i = 0;i<n;i++) {
    int x;
    cin>>x;
    //cout<<"mon: "<<mon<<"\n";
    if(x>=k) {
      mon += x;
    }else if(x==0&&mon) {
      mon--;
      ans++;
    } 
  }
  cout<<ans<<"\n";
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}