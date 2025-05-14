#include <iostream>
#include <vector>

using namespace std;

string st = "narek";

int isNarek(char ch) {
  if(ch == 'n' || ch == 'a' || ch == 'r' || ch == 'e' || ch == 'k') { return 1; }
  return 0;
}

void solve() {
  int n,m;
  cin>>n>>m;
  int s_ptr = 0;
  int c_sum = 0;
  int n_sum = 0;
  int curr_g = 0;

}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}