// https://codeforces.com/contest/1879/problem/C

#include <bits/stdc++.h>

using namespace std;

unsigned long long int ans(unsigned long long int n,unsigned long long int nn){

  unsigned long long int pr = 1;
  // unsigned long long int rem = nn%998244353;
  // unsigned long long int lrem = 1;
  nn = nn%998244353;
  for(unsigned long long int i=n;i>1;i--){
    pr *= i;
    if(pr>=998244353){
      nn *= pr%998244353;
      pr = 1;
      nn %= 998244353;
    }
  }
  // lrem = (lrem*pr)%998244353;
  nn *= pr%998244353;
  nn %= 998244353;
  return nn;
}

int main(){

  unsigned long long int t;
  cin>>t;
  while(t--){

    string st;
    cin>>st;
    unsigned long long int count = 1;
    unsigned long long int ops  = 0;
    unsigned long long int ways = 1;
    unsigned long long int grps = 0;

    for(unsigned long long int i= 1;i<st.length();i++){

      if(st[i]==st[i-1]) count++;
      else{
        if(count>1){
          ops += count -1;
          ways *= count;
          ways %= 998244353;
          count = 1;
          grps++;
        }
      }
    }
    if(count>1){
      ops += count -1;
      ways *= count;
      grps++;
    }
    cout<<ops<<" "<<ans(ops,ways%998244353)<<endl;
  }
}