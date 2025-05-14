#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len,k;
    cin>>len>>k;
    int counting = 0;
    int count = 0;
    while(len--){
      char ch;
      cin>>ch;
      if(counting==0&&ch=='B'){
        count++;
        counting++;
        if(counting==k) counting = 0;
      }
      else if(counting!=0){
        counting++;
        if(counting==k)
          counting = 0;
      }
    }
    cout<<count<<endl;
  }
}