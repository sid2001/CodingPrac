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
      if(x==0)
        continue;
      product *= x;
    }
    if(mi>0){
      product = (product/mi) * (mi+1);
    }
    if(m==0)
      cout<<product*0<<endl;
    else cout<<product<<endl;

    // unsigned long long pro =  product;
    // if(mi>0){
    //   for(auto i : vec){
    //     product = max((pro/i)* (i+1),product);
    //   }
    // }
  }
}