#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin>>t;
  while(t--){

    unsigned long long product = 1;
    unsigned long long ele;
    unsigned long long mi = 0 ;
    cin>>ele;
    int e = ele;
    int zeroCount = 0;
    int first = 1;
    unsigned long long m = 0;
    vector<unsigned long long> vec;
    while(ele--){
      unsigned long long x;
      cin>>x;
      vec.push_back(x);
      m = max(m,x);
      if(mi == 0&&first){
        mi = x;
        first = 0;
      }
      else    
        mi = min(x,mi);
      if(x==0){
        zeroCount++;
        continue;
      }
      product *= x;
    }
    unsigned long long pro =  product;
    if(m==0||zeroCount>1){
      if(e==1)    product = 1;
      else product = 0;
    }
    else if(mi>0){
      for(auto i : vec){
        product = max((pro/i)* (i+1),product);
      }
    }
    
    cout<<product<<endl;

    
  }
}