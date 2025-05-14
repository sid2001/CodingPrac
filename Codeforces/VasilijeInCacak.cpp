#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    unsigned long long int n,k,x;
    cin>>n>>k>>x;
      unsigned long long int ss = k*(k+1)/2;
      if(x>=ss&&x<=(k*(2*n-k+1))/2){
        cout<<"YES"<<endl;
      }
      else cout<<"NO"<<endl;
  }
}