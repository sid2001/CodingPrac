#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;

void query(vector<ull> &vec, ull q) {
  for(ull i = 0; i < q; i++){
    ull a,b;
    cin>>a>>b;
    if(a==1) {
      cout<<vec[b-1]<<"\n";
    } else {
      cout<<vec[b-1] - vec[a-2]<<"\n";
    }
  }
  return;
}

int main() {
  ull n,q;
  cin >> n >>q;
  vector<ull> vec(n,0);
  cin >> vec[0];
  for(ull i = 1;i<n;i++){
    cin>>vec[i];
    vec[i] += vec[i-1];
  }
  query(vec,q);

  return 0;
}