#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void solve() {
  ll n, m, q;
  cin>>n>>m>>q;
  ll a, b;
  ll q1;
  cin>>a>>b;
  cin>>q1;
  if((a-q1)*(b-q1)<0) {
    cout<<abs(a-b)/2<<"\n";
  } else if(q1 < a) {
    ll mini = min(a,b);
    cout<<mini-1<<"\n";
  } else  {
    ll maxi = max(a,b);
    cout<<n-maxi<<"\n";
  }

}

int main() {
  ll t;
  cin>>t;
  while(t--) {
    solve();
  }

  return 0;
}