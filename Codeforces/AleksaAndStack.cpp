#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int len;
    cin>>len;
    int l = 1;
    while(len--){
      cout<<l * 3 + 1<<" ";
      l++;
    }
    cout<<endl;
  }
}