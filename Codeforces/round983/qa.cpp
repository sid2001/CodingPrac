#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int on = 0;
    int x;
  for(int i = 0; i < 2*n; i++) {
    cin >> x;
    on += x;
  } 
  int mins = on%2;
  int maxs = 0;
  if(on > n) {
    maxs = n - (on - n);
  }else {
    maxs = on;
  }
  cout << mins<<" "<<maxs<<"\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}