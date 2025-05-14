#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len;
    cin>>len;
    int l = len;
    vector<ll> vec;
    vector<ll> seq;
    while(len--){
      ll x;
      cin>>x;
      vec.push_back(x);
    }
    for(int i = l-1;i>=0;i--){
      seq.push_back(vec[i]);
    }
    ll currHeight = 1;
    int findx = 0;
    int lastBlock = vec[0];
    int ans = 1;
    if(vec[0]!=l)
      ans = 0;
    else{
      for(int i = 1;i<l;i++){
        if(lastBlock == vec[i]){
          currHeight++;
          if(currHeight>seq[findx]){
            ans = 0;
            break;
          }
        }
        else{
        ll diff = lastBlock-vec[i];
        lastBlock  = vec[i];
        findx = findx + diff;
        currHeight++;
        if(!(seq[findx]>=currHeight)&& !(seq[findx-1]!=currHeight-1)){
          ans = 0;
          break;
        }
        }
      }
    }
    if(ans){
      cout<<"YES"<<endl;
    }
    else
      cout<<"NO"<<endl;
  }
}