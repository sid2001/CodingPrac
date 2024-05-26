#include<iostream>
#include<string.h>

using namespace std;

int solve(string &s){
  char curr = s[0];
  int count = 1;
  int mcount = 1;
  for(int i = 1; i < s.size();i++){
    if(s[i]==curr){
      count++;
      mcount = max(mcount,count);
    }else{
      curr = s[i];
      count = 1;
    }
  }
  return mcount;
}
int main(){
  string s;
  cin>>s;
  cout<<solve(s)<<endl;
  return 0;
}