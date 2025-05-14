#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int ch = 0;
    char chh[3] = {'a','b','c'};
    int flag = 0;
    while(ch<3){
      char c;
      cin>>c;
      if(c==chh[ch])
        flag = 1;
      ch++;
    }
    if(flag){
      cout<<"YES"<<endl;
    }
    else 
      cout<<"NO"<<endl;
    flag = 0;
  }
}