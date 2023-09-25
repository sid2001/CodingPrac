// https://codeforces.com/contest/1879/problem/C

#include <bits/stdc++.h>

using namespace std;

unsigned int pro(unsigned int n){

  unsigned int pr = 1;
  for(unsigned int i=n;i>1;i--){
    pr *= i;
  }
  return pr;
}

int main(){

  unsigned int t;
  cin>>t;
  while(t--){

    string st;
    cin>>st;
    unsigned int count = 1;
    unsigned int ops  = 0;
    unsigned int ways = 1;
    // unsigned int grps = 0;

    for(unsigned int i= 1;i<st.length();i++){

      if(st[i]==st[i-1]) count++;
      else{
        if(count>1){
          ops += count -1;
          ways *= count;
          count = 1;
          // grps++;
        }
      }
    }
    if(count>1){
      ops += count -1;
      ways *= count;
      // grps++;
    }
    cout<<ops<<" "<<ways*pro(ops)<<endl;
  }
}