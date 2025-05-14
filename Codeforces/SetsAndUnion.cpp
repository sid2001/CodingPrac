#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int anum;
    cin>>anum;
    
    vector<vector<int>> iset(anum);
    vector<vector<int>> vec(51);
    int l = anum;
    int tot = 0;
    int c = 0;
    while(l--){
      int x;
      cin>>x;
      iset[c].push_back(x);
      while(x--){
        int ele;
        cin>>ele;
        if(vec[ele].empty()) {
          tot++;
        }
        vec[ele].push_back(c);
        iset[c].push_back(ele);
      }
      c++;
    }
    if(anum == 1){
      cout<<0<<endl;
      continue;
    }
    vector<vector<int>> miset;
    for(auto i:iset){
      if(i.size()-1==tot) continue;
      miset.push_back(i);
    }
    vector<vector<int>> mvec(51);
    int cc = 0;
    for(auto i:miset){
      for(int j =1;j<i.size();j++){
        mvec[i[j]].push_back(cc);
      }
      cc++;
    }
    int mn = 51;
    for(auto i:mvec){
      int iii = i.size();
      mn = min(mn,iii);
    } 
    vector<int> ans(miset.size(),0);
    for(auto i:mvec){
      if(i.size()==mn){
        for(auto j:i){
          ans[j]++;
        }
      }
    }
    int ansmin = 51;
    int lko = -1;
    int fl = 0;
    for(auto kk:ans){
      if(ansmin>kk){
        ansmin = kk;
        lko = fl;
      }
      else if(ansmin == kk){
        if(miset[lko][0]>miset[fl][0]){
          ansmin = kk;
          lko = fl;
        }
      }
      fl++;
    }
    cout<<tot-ansmin-1<<endl;
  }
}