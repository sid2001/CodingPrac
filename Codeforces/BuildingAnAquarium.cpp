#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){
    int len,w;
    cin>>len>>w;
    int l = len;
    long long h = 0;
    long long sum = 0;
    while(len--){

      long long x;
      cin>>x;
      sum += x;
    }
    long long ans = (sum+w)/l;
    if(ans==0){
      cout<<1<<endl;
    }
    else if(w==1)
      cout<<2<<endl;
    else
      cout<<ans<<endl;
  }
}