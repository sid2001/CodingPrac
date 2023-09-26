// https://codeforces.com/contest/1882/problem/0

#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len;
    cin>>len;
    unsigned int val = 0;
    while(len--){

      unsigned int x;
      cin>>x;
      val++;
      if(val==x){
        val++;
      }
    }
    cout<<val<<endl;
  }
}