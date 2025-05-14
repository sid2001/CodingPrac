#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
  int t;
  while(t--) {
    int n;
    cin>>n;
    unordered_map<int,vector<int>> mp;
    for(int i = 0; i<n; i++) {
      int x;
      cin>>x;
      mp[x].push_back(i);
    }
    int nn;
    cin>>nn;
    
  }
}