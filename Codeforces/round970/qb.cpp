#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(){
  int n;
  cin>>n;
  string st;
  cin>>st;
  int r = (int) sqrt(n);
  if(r*r != n){
    cout<<"NO"<<"\n";
    return;
  }
  for(int i = 0; i<r; i++){
    for(int j = 0; j<r; j++){
      int idx = r*i + j;
      if(i==0 || i == r-1 || j==0 || j==r-1){
        if(st[idx] == '1') continue;
        else {
          cout<<"NO"<<"\n";
          return;
        }
      }else{
        if(st[idx]=='0') continue;
        else {
          cout<<"NO"<<"\n";
          return;
        }
      }
    }
  }
  cout<<"YES"<<"\n";
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}