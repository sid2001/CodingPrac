// https://codeforces.com/contest/1879/problem/B

#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len;
    cin>>len;
    vector<unsigned long long> crow(len);
    unsigned long long cmin,rmin;
    unsigned long long csum = 0;
    unsigned long long rsum = 0;

    vector<unsigned long long> ccol(len);
    for(int i=0;i<len;i++){
      cin>>crow[i];
      rsum += crow[i];
      if(i==0) rmin = crow[i];
      else rmin = min(rmin,crow[i]);
    }
    for(int i = 0;i<len;i++){
      cin>>ccol[i];
      csum += ccol[i];
      if(i==0) cmin = ccol[i];
      else cmin = min(cmin,ccol[i]);
    }
    unsigned long long cwsum = csum + len*rmin;
    unsigned long long rwsum = rsum + len*cmin;
    cout<<min(cwsum,rwsum)<<endl;
  }
}