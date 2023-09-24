// https://codeforces.com/contest/1879/problem/0

#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len;
    cin>>len;
    unsigned long long ms, me;
    cin>>ms>>me;
    len--;
    int ans = 0;
    while(len--){
      unsigned long long ps,pe;
      cin>>ps>>pe;
      if(ps>=ms&&pe>=me)
        ans = -1;
    }
    if(ans==-1) cout<<ans<<endl;
    else cout<<ms<<endl;
  }
}