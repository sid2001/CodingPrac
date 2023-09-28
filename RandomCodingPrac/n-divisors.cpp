// https://www.spoj.com/submit/NDIV/
#include <bits/stdc++.h>
#define uli long long int
using namespace std;

void solve(uli iquo,uli i,vector<int> &vec,uli a,uli b){

  for(uli j = iquo;j*i<=b;j++){
    vec[j*i - a]++;
  }
}

int main(){
  
  uli a,b,n;
  cin>>a>>b>>n;
  vector<int> vec(b+1-a,1);

 
  for(uli i = 3;i<=sqrt(b);i++){
    uli iquo = a/i;
    if(iquo<i) iquo = i;
    solve(iquo,i,vec,a,b);
  }
  int count = 0;
  for(int i =0;i<b-a+1;i++){
    if((i+a)!=1) vec[i]++;
    if((i+a)%2==0&&(i+a)!=2) vec[i]++;
    if(vec[i]==n) count++;
  }
  cout<<count<<endl;
}