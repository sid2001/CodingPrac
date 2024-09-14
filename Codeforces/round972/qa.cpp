#include <iostream>
#include <vector>

using namespace std;
char arr[5] = {'a','e','i','o','u'};
int ar[5] = {0,0,0,0,0};


void display(vector<char> &vec) {
  for(auto i:vec) {
    cout<<i;
  }
  cout<<"\n";
}
void solve() {
  int n;
  cin>>n;
  int i = 0;
  int j = n-1;
  vector<char> ans(n);
  int flag = 1;
  int idx = 0;
  int nn = 5;
  int fact = n/5;
  int ff = fact;
  for(int i = 0; i<5; i++) {
    ar[i] = fact;
  }
  int fl = n - fact * 5;
  for(int i = 0; i<fl; i++) {
    ar[i]++;
  }
  for(auto ii:ar) {
    int k = ii;
    //cout<<k<<" sd"<<endl;
    while(k--) {
      if(flag){
        ans[i++] = arr[idx];
      }else{
        ans[j--] = arr[idx];
      }
    }
    idx++;
    flag = !flag;
  }
  display(ans);
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
  return 0;
}