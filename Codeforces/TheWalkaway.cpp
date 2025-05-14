#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    ll n,m,d;
    cin>>n>>m>>d;
    int mm = m;
    vector<ll> vec;
    while(m--){
      ll x;
      cin>>x;
      vec.push_back(x);
    }
    int count = 0;
    int cookies = 1;
    for(int i=0;i<mm;i++){

      if(i==0&&vec[i]==1){
        continue;
      }
      else if(i==0){
        cookies += (vec[i]-1-1)/d +1;
      }
      else if(i==mm-1){
        if(vec[i]==n){
          cookies += (vec[i]-1-vec[i-1])/d + 1;
        }
        else{
          cookies += (vec[i]-1-vec[i-1])/d + 1;
          cookies += (n-vec[i])/d;
        }
      }
      else{
        cookies += (vec[i]-1-vec[i-1])/d + 1;
      }
    }
    int diff = 0;
    int maxDiff = 0;
    string shops="";
    for(int i = 0;i<mm;i++){
      if(i==0&&vec[i]==1){
        continue;
      }
      else if(i==0){
        diff = (((vec[i]-1-1)/d + 1)+((vec[i+1]-vec[i]-1)/d +1))-((vec[i+1]-1-1)/d + 1);
        if(diff==maxDiff)
          shops += to_string(i);
        else if(diff>maxDiff){
          shops = to_string(i);
          maxDiff = diff;
        }
      }
      else if(i==mm-1){
        if(vec[i]==n){
          diff = (((vec[i]-vec[i-1]-1)/d + 1)+((n+1-vec[i]-1)/d + 1))-((n+1-vec[i-1]-1)/d + 1);
          if(diff==maxDiff){
            shops += to_string(i);
            continue;
          }
          else if(diff>maxDiff){
            maxDiff = diff;
            shops = to_string(i);}
            
        }
        else {
          diff = (((vec[i]-vec[i-1]-1)/d + 1)+((n-vec[i])/d))-((n-vec[i-1])/d);
          if(diff==maxDiff)
            shops += to_string(i);
          else if(diff>maxDiff){
            shops = to_string(i);
            maxDiff = diff;
          }
        }
      }
      else{
        diff = (((vec[i]-vec[i-1]-1)/d + 1)+((vec[i+1]-vec[i]-1)/d + 1))-((vec[i+1]-vec[i-1]-1)/d + 1);
        if(diff==maxDiff)
          shops += to_string(i);
        else if(diff>maxDiff){
          shops = to_string(i);
          maxDiff = diff;
        }
      }
    }
    if(maxDiff!=0)
      cout<<cookies-1<<" "<<shops.length()<<endl; 
    else
      cout<<cookies<<" "<<shops.length()<<endl; 
  }
}