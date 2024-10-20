#include <iostream>
#include <vector>
#include <cmath>
#define ull unsigned long long

using namespace std;

void solve() {
  ull k;
  cin>>k;
  ull x = ceil(k/3.0);
  cout<<k + x<<"\n";

  return;
}

int main() {
  int t;
  cin>>t;

  while(t--){
    solve();
  }
}