#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &vec){
  for(int i = 0; i < vec.size(); i++){
    if(vec[i] == 0){
      return i+1;
    }
  }
  return -1;
}
int main(){
  int n,x;
  cin>>n;
  vector<int> vec(n,0);
  for(int i = 0; i < n-1; i++){
    cin>>x;
    vec[x-1]++;
  }
  cout<<solve(vec)<<endl;
  return 0;
}