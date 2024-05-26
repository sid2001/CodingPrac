#include<iostream>
using namespace std;

bool isEven(long long n){
  if(n%2==0){
    return true;
  }
  return false;
}
void solve(long long n){
  while(n!=1){
    cout<<n<<" ";
    if(isEven(n)){
      n /= 2;
    }else{
      n = 3*n+1;
    }
  }
  cout<<n<<" "<<endl;
}
int main(){

  long long n;
  cin>>n;
  solve(n);

  return 0;
}