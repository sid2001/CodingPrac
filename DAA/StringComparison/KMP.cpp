#include <iostream>
#include <vector>
using namespace std;

void computePi(string &pat,vector<int> &pi){
  int m = pat.length();
  int k = 0;
  pi[k] = 0;
  for(int i = 1;i<m;i++){
    while(k>0&&pat[k]!=pat[i])
      k = pat[k-1];
    if(pat[k]==pat[i])
      k++;
    pi[i] = k;
  }
  return;
}

void kmp(string &str,string &pat){
  int m = pat.length();
  int n = str.length();

  vector<int> pi(m,0);
  computePi(pi);
  int k = 0;

  for(int i = 0;i<n;i++){
    while(k>0&&pat[k]!=str[i]){
      k = pi[k-1];
    }
    if(pat[k]==str[i]) k++;

    if(k==m){
      
    }
  }
}

int main(){
  string pat,str;
  cin>>str>>pat;
  kmp(str,pat)
}