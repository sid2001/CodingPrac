#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  string n;
  for(int i = 0; i < t; i++) {
    cin >> n;
    if(n.length() > 2) {
      int num = stoi(n);
      string st = (n.substr(0, 2));
      int a = stoi(st);
      //cout<<"a"<<a<<"\n";
      if(a != 10) {
        cout<<"NO"<<"\n";
        continue;
      }else {
        string stl = n.substr(2, n.length());
        if(stl[0] == '0' || stoi(stl) < 2) {
          //cout<<"stl"<<stl<<"\n";
          cout<<"NO"<<"\n";
          continue;
        } else {
          cout<<"YES"<<"\n";
          continue;
        }
      }
    } else {
      cout<<"NO"<<"\n";
    }
  }
  return 0;
}