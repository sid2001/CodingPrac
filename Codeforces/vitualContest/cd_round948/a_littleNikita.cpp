#include<iostream>

using namespace std;

int main(){
  int n,m,t;

  cin>>t;
  while(t--){
    cin>>n>>m;

    if(n<m){
      cout<<"NO"<<"\n";
    }else{
      cout<<((n-m)%2==0?"YES":"NO")<<"\n";
    }
  }
  return 0;
}