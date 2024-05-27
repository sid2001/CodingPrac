#include<iostream>
using namespace std;

void solve(int csum, int sum,int &ways){
  if(csum>=sum) return;

  for(int i = 1;i<=sum-csum;i++){
    csum += i;
    if(csum==sum){
      ways++;
      return;
    }else{
      solve(csum,sum,ways);
      csum -= i;
    }
  }
}
int main(){
  int n,ways=0;
  cin>>n;
  solve(0,n,ways);
  cout<<ways;
  return 0;
}