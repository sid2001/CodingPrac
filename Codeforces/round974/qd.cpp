#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void solve() {
  int n,d,k;
  cin>>n>>d>>k;

  vector<int> start(n+1,0);
  vector<int> end(n+1,0);
  //memset(start,0,sizeof(start));
  //memset(end,0,sizeof(end));
  for(int i = 0; i<k; i++) {
    int x,y;
    cin>>x>>y;
    start[x]++;
    end[y]++;
  }
  int s_b = 1;
  int s_m = 1;
  int max_b = 0;
  int c_d = 0;
  int min_m = 0;
  for(int i = 1; i<= d; i++) {
    if(start[i]) {
      max_b+= start[i];
      min_m+= start[i];
    }
    c_d+= start[i];
  }
  //cout<<"max_b: "<<max_b<<" min_m: "<<min_m<<"\n";
  for(int i = 2;i<=n-d+1;i++) {
    if(start[i+d-1]) c_d+= start[i+d-1];
    //cout<<"c_d2: "<<c_d<<"\n";
    if(end[i-1]) c_d-=end[i-1];
    //cout<<"c_d: "<<c_d<<"\n";
    if(max_b < c_d) {
      max_b = c_d;
      s_b = i;
    }
    if(min_m > c_d) {
      min_m = c_d;
      s_m = i;
    }
  }
  cout<<s_b<<" "<<s_m<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}