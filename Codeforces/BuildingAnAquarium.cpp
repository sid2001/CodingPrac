#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len;
    unsigned long long k;
    cin>>len>>k;
    vector<unsigned long long> vec;
    int l = len;
    unsigned long long sum = 0;
    while(len--){
      unsigned long long x;
      cin>>x;
      sum += x;
      vec.push_back(x);
    }

    sort(vec.begin(),vec.end());
    vector<pair<unsigned long long, unsigned long long>> pvec;
    auto it = --vec.end();
    unsigned long long count = 0;
    unsigned long long value = 0;
    cout<<*it<<endl;
    while(it!= vec.begin()){

      if(value == 0){
        value = *it;
        count++;
        it--;
      }
      else if(value != *it ){
        pvec.push_back(make_pair(value,count));
        value = *it;
        count = 1;
        it--;
      }
      else if(value == *it){
        count++;
        it--;
      }
      if(it==vec.begin()){
          if(value==*it){
            pvec.push_back(make_pair(value,count+1));
          }
          else{
            pvec.push_back(make_pair(value,count));
            pvec.push_back(make_pair(*it,1));
          }
        }
    }
    auto itt = pvec.begin();
    unsigned long long limit = itt->first;
    while(true){
    if(l*limit-sum<=k){

      unsigned long long ans = (k+sum)/l;
      cout<<ans<<endl;
      break;
    }
    else{
      sum = sum - (itt->first * itt->second);
      l -= itt->second;
      itt++;
      limit = itt->first;
    }
    }
  }
}