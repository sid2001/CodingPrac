#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin>>n;
  int flag = 1;
  string st = "";
  while(n) {
    int x;
    if(flag)
      cout<<"? "<<st + "1"<<"\n";
    else 
      cout<<"? "<<"1" + st<<"\n";
    cout.flush();
    cin>>x;
    if(x == 1) {
      if(flag) {
        st = st + "1";
      } else {
        st = "1" + st;
      }
      n--;
    } else {
      if(flag) {
        cout<<"? "<<st + "0"<<"\n";
        cout.flush();
        cin>>x;
        if(x == 1) {
          st = st + "0";
          n--;
        } else {
          flag = 0;
        }
      } else {
        st = "0" + st;
        n--;
      }
    }
  }
  cout<<"! "<<st<<"\n";
  cout.flush();
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }

  return 0;
}