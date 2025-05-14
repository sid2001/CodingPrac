#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(string &st1, string &st2, vector<vector<int>> &vec, int n, int m, int c1 = 0, int c2 = 0,int op = 0){
  //if(c1==n-1 && c2==m-1 && )
  if(c1 == n) return m-c2;
  if(c2 == m) return n-c1;

  if(vec[c1][c2]!=INT_MAX) return vec[c1][c2];
  int r = INT_MAX, d = INT_MAX, a = INT_MAX, s = INT_MAX;
  if(!(st1[c1] == st2[c2])) {
    r = 1 + solve(st1, st2, vec,n,m,c1+1,c2+1,op);
    d = 1 + solve(st1, st2, vec,n, m, c1+1, c2,op);
    a = 1 + solve(st1, st2, vec,n,m,c1,c2+1,op);
  }
  //else{
  if(st1[c1] == st2[c2])
    s = solve(st1, st2, vec,n,m,c1+1,c2+1,op);
  //}
  return vec[c1][c2] = min(r,min(d,min(s,a)));
}

int main() {
  string st1,st2;
  cin>>st1>>st2;
  int n = st1.length();
  int m = st2.length();
  vector<vector<int>> vec(n,vector<int>(m,INT_MAX));

  cout<<solve(st1,st2,vec,n,m);
}