//TLE
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void display(vector<int> &vec) {
  for(auto i:vec) {
    cout<<i<<" ";
  }
  cout<<endl;
}

int arrange(vector<ll> &vec) {
  int flag = 0;
  int indx = 0;
  while(indx<vec.size()-1) {
    if(vec[indx]>vec[indx+1]) {
      ll x = vec[indx] + vec[indx+1];
      vec[indx] = x/2;
      vec[indx+1] = x%2==0?x/2:x/2 + 1;
      flag = 1;
    }
    indx++;
  }
  //display(vec);
  return flag;
}

void solve() {
  int n;
  int flag = 0;
  cin>>n;
  vector<ll> vec(n,0);
  for(int i = 0; i<n; i++) {
    cin>>vec[i];
  }
  while(true) {
    int flag = arrange(vec);
    if(!flag) break;
  } 
  cout<<*max_element(vec.begin(),vec.end())-*min_element(vec.begin(),vec.end())<<endl;

  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}