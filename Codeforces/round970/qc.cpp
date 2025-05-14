#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int a, b;
  cin>>a>>b;
  int i = 1;
  if(a==b) {
    cout<<1<<"\n";
    return;
  }
  int count = 0;
  while(true) {
    if(i*(i-1)/2 == b-a) {
      count++;
      break;
    } else if(i*(i-1)/2 > b-a){
      break;
    }
    count++;
    i++;
  }
  cout<<count<<endl;
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}