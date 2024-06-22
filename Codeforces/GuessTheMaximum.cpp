#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &vec, int &minmax, int &maxi){

  for(int i = 1; i < vec.size(); i++){
    maxi = max(vec[i-1],vec[i]);
    minmax = min(minmax,maxi);
  }
  cout<<minmax-1<<"\n";
  return;
}
int main(){
  int t;
  cin>>t;
  
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    int minmax = 1000000001;
    int maxi = -1;
    for(int i = 0; i < n; i++){
      cin>>vec[i];
    }    

    solve(vec,minmax,maxi);
  }
  return 0;
}