#include<iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vector<int> vec(n,0);
    int flag = 1;
    int ini;
    cin>>ini;
    vec[ini-1] = 1;
    //cout<<"sds";
    for(int i = 1; i<n;i++) {
      int x;
      cin>> x;
      x = x -1;
      //cout<<"prev: "<<prev<<" x: "<<x<<"\n";
      if(x == n - 1 && vec[x-1] != 1 ){
        //cout<<abs(x - prev)<<"\n";
        flag = 0;
      } else if(x == 0 && vec[x+1] != 1) {
        flag = 0;
      } else if(vec[x-1] != 1 && vec[x+1] != 1) {
        flag = 0;
      }
      vec[x] = 1;
    }
    if (flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
  }
  return 0;
}