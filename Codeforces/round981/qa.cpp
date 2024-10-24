#include <iostream>
#include <vector>
 
using namespace std;

void solve() {
  int n;
  cin>>n;
  int i = 1;
  int sign = -1;
  int sum = 0;
  while(abs(sum)<=n){
    sum = sum + sign*(i*2 - 1);
    sign = -sign;
    i++;
  }
  if(i%2==0) {
    cout<<"Sakurako"<<"\n";
  }else{
    cout<<"Kosuke"<<"\n";
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