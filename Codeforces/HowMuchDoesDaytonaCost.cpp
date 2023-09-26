// https://codeforces.com/contest/1878/problem/0

#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len,num;
    cin>>len>>num;
    bool flag=false;
    vector<int> vec(101,0);
    while(len--){

      int x;
      cin>>x;
      if(x==num)
        flag = true;
    }
    if(flag==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
}