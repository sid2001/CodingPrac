#include <iostream>
#include <vector>

using namespace std;

void solve(){
  int a, b;
  cin>>a>>b;
  int ra = a;
  int rb = b*2;
  if(a*b==0) {
    if(a%2!=0 || b%2!=0) cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
  } else if(a%2==0 && b%2==0) cout<<"YES"<<"\n";
  else {
    if(ra>=rb) {
      ra = ra - rb;
      if(ra%2==0) cout<<"YES"<<"\n";
      else cout<<"NO"<<"\n";
    } else {
      rb = rb - ra;
      if(rb%2!=0) cout<<"NO"<<"\n";
      else cout<<"YES"<<"\n";
    }
  }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}