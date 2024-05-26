#include<iostream>

using namespace std;

int main(){
  int n;
  unsigned long long x,prev;
  bool flag = true;
  long long moves = 0;
  cin>>n;
  while(n--){
    cin>>x;
    if(flag){
      prev = x;
      flag = false;
    }else{
      moves += x<prev?prev-x:0;
      prev = x<prev?prev:x;
    }
  }
  cout<<moves<<endl;
  return 0;
}