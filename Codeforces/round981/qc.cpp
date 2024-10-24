#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &vec, int i, int j) {
  int temp = vec[i];
  vec[i] = vec[j];
  vec[j] = temp;
  return;
}
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++) {
    cin>>vec[i];
  }
  int before = 0, after = 0;
  for(int i = 0; i < n; i++) {
    if(vec[i] != vec[(n-1)-i]){
      before = 0;
      after = 0;
      int nn = n-1-i;
      if(i < n-1 &&vec[i] == vec[i+1]) before++;
      if(i > 0 && vec[i] == vec[i-1]) before++;
      if(nn < n-1 && vec[nn] == vec[nn+1]) before++;
      if(nn > 0 && vec[nn] == vec[nn-1]) before++;

      if(i < n-1 &&vec[nn] == vec[i+1]) after++;
      if(i > 0 && vec[nn] == vec[i-1]) after++;
      if(nn < n-1 && vec[i] == vec[nn+1]) after++;
      if(nn > 0 && vec[i] == vec[nn-1]) after++;

      if(after < before) swap(vec, i, nn);
    }
  }
  int ans = 0;
  for(int i = 0; i < n-1; i++) {
    if(vec[i] == vec[i+1]) ans++;
  }

  cout<<ans<<"\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}