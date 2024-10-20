#include <vector>
#include <iostream>

using namespace std;

void solve() {
  int n;
  cin>>n;
  int m_min = 1000000;
  int m_max = -1;
  int x;
  for(int i = 0; i < n; i++){
    cin>>x;
    m_min = min(x,m_min);
    m_max = max(x, m_max);
  }
  int ans = (m_max-m_min)*(n-1) ;
  cout<< ans<<"\n";
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}