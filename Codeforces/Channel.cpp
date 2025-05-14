#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int n,a,q;
    cin>>n>>a>>q;
    int qq = q;
    int plus = 0;
    int minus = 0;
    int aa = a;
    if(a==n)
      {
        cout<<"YES"<<endl;
        while(qq--){
          char ch;
          cin>>ch;
        }
        continue;
      }
    // int flag = 0;
    // int minusMaxx = 0;
    // int plusMaxx = 0;
    int receivedAndOffline = 0;
    while(qq--){
      char ch;
      cin>>ch;
      if(ch=='+'){
        plus++;
        if(receivedAndOffline==0)
          a++;
        else
          receivedAndOffline--;
        }
      else{
        minus++;
        receivedAndOffline++;
      }
    }
    if(a>=n)
      cout<<"YES"<<endl;
    else if(aa+plus>=n)
      cout<<"MAYBE"<<endl;
    else
      cout<<"NO"<<endl;
  }
}