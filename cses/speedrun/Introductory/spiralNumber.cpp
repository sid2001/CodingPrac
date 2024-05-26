#include<iostream>

using namespace std;

long long getValue(long long &imax,long i, long j){
  long long sum = (imax-1)*(imax-1);
  if(i==imax){
      sum += imax + (imax-j);
    }else{
      sum += i; 
    }
  return sum;
}

long long solve(long long x, long long y){
  long long imax = max(x,y);
  if(imax%2==0){
    return getValue(imax,x,y);
  }else{
    return getValue(imax,y,x);
  }
}
int main(){
  int t;
  long long x,y;
  cin>>t;
  while(t--){
    cin>>x>>y;
    cout<<solve(x,y)<<" ";
  }
  cout<<endl;
  return 0;
}