#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){

  int t;
  cin>>t;
  while(t--){

    ll n,k;
    cin>>n>>k;
    ll nn = n;
    vector<ll> vec;
    ll sum = (n*(n+1))/2;
    ll s = 0;
    while(nn--){
      ll x;
      cin>>x;
      s += x;
      vec.push_back(x);
    }
    ll missing = sum - s;
    ll rem = k%(n+1);
    if(rem==0){
      for(auto i:vec)
        cout<<i<<" ";
      cout<<endl;
    }
    else{
      ll pivot = n-rem;
      pivot++;
      ll nu = n;
      while(nu--){
        if(pivot==n){
          cout<<missing<<" ";
          pivot = 0;
        }
        else{
          cout<<vec[pivot]<<" ";
          pivot++;
        }
      }
      cout<<endl;
    }
  }
}