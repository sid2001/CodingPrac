#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){
    int len;
    cin>>len;
    vector<ll> vec;
    int l =len;
    while(len--){
      ll x;
      cin>>x;
      vec.push_back(x);
    }
    vector<ll> seq;
    seq.push_back(vec[0]);
    for(int i = 1;i<l;i++){
      if(vec[i-1]<=vec[i]) seq.push_back(vec[i]);
      else{
        seq.push_back(vec[i]);
        seq.push_back(vec[i]);
      }
    }
    cout<<seq.size()<<endl;
    for(auto i:seq){
      cout<<i<<" ";
    }
    cout<<endl;
  }
}