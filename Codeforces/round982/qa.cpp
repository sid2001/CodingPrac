#include <iostream>
#include <vector>

using namespace std;

void solve(){
  int n;
  cin>>n;
  int mw = 0, mh = 0;
  int w,h;
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin>>w>>h;
    if(w>mw) {
      ans += 2*(w-mw);
      mw = w;
    }
    if(h>mh){
      ans += 2*(h-mh);
      mh = h;
    }
  }
  cout<<ans<<"\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}