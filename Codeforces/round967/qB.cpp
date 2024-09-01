#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> vec) {
  for(auto i:vec) {
    cout<<i<<" ";
  }
  cout<<"\n";
}
void solve() {
  int n;
  cin>>n;
  vector<int> vec(n,-1);
  if(n==1) {
    cout<<1<<"\n";
    return;
  } else if(n==2) {
    cout<< -1 <<"\n";
    return;
  } else if(n==3) {
    cout<<3<<" "<<1<<" "<<2<<"\n";
    return;
  } else {
    if(n%2==0) {
      cout<< -1 <<"\n";
      return;
      } else {
        int x = 1;
        int idx = 1;
        while(idx < n) {
          vec[idx] = x;
          x++;
          idx += 2;
        }
        idx--;
        while(idx>=0) {
          vec[idx] = x;
          x++;
          idx -= 2;
        }
      }
    }
    display(vec);
    return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}