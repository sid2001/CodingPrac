#include <vector>
#include <iostream>

using namespace std;

int ssolve(int num, int flag) {
  if(num==1) {
    if(flag==1){
      return 1;
    }else{
      return 0;
    }
  }else{
    if(flag==1){
      return 1;
    }else return 0;
  }
  if(flag==0 && num%10 == 0){
    return 0;
  }else{
    if(num%10 == 1){
      if(flag == 1){
        return ssolve(num/10,0);
      }else{
        while(num > 9){
          num /= 10;
        }
        return ssolve(num,0);
      }
    }else{
      return ssolve(num/10,0);
    }
  }
}

void solve() {
  int n;
  cin>>n;
  string num;
  cin>>num;
  int idx = 0;
  int flag = 0;
  if(num[0]=='1'||num[n-1]=='1') flag = 1;
  for(int i = 1; i < n; i++) {
    if(num[i-1]=='1'&&num[i]=='1') flag = 1;
  }
  if(flag){
    cout<<"YES"<<"\n";
  }else{
    cout<<"NO"<<"\n";
  }
}

int main() {
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}