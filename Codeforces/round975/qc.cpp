//not solved
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ull unsigned long long

using namespace std;

void solve() {
  ull n,k;
  cin>>n>>k;
  vector<ull> vec(n);
  ull mm = 0;
  int tot = 0;
  for(int i = 0; i<n; i++) {
    cin>>vec[i];
    tot += vec[i];
    mm = max(mm, vec[i]);
  }
  sort(vec.begin(), vec.end());
  ull decks = mm;
  while(true) {
    ull m = tot%decks;
    if(m==0) {
      if(k<decks) {
        cout<<tot/decks<<"\n";
      }else{
        for(int i = 0; i<n; i++) {
          ull need = mm*decks - tot;   
          if(need<=k){
            decks++;
            cout<<decks<<"\n";
            return;
          }   
      }
    } 
  }else{
    if(k<tot/decks){

    }
    while(true) {
      decks++;
    }

  }
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}