// https://codeforces.com/contest/1879/problem/C

#include <bits/stdc++.h>

using namespace std;

int pro(int n){

  int pr = 1;
  for(int i=n;i>1;i--){
    pr *= i;
  }
  return pr;
}

int main(){

  int t;
  cin>>t;
  while(t--){

    string st;
    cin>>st;
    int count = 1;
    int ops  = 0;
    int ways = 1;
    int grps = 0;

    for(int i= 1;i<st.length();i++){

      if(st[i]==st[i-1]) count++;
      else{
        if(count>1){
          ops += count -1;
          ways *= pro(count);
          count = 1;
          grps++;
        }
      }
    }
    if(count>1){
      ops += count -1;
      ways *= pro(count);
      grps++;
    }
    cout<<ops<<" "<<ways*pro(grps)<<endl;
  }
}