#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--){

    int len;
    unordered_map<int,int> vec;
    cin>>len;
    int l = len;
    int indx = 1;
    while(l--){
      int x;
      cin>>x;
      vec[x] = indx;
      indx++;
    }
    int check = len;
    int count = 0;
    while(check-1){

      if(vec[check]<vec[check-1])
        count++;
      check--;
    }
    cout<<count<<endl;
    
  }
  return 0;
}