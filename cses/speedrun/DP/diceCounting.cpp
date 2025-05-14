#include <iostream>
#include <vector>
using namespace std;

long long solve(long long n,vector<long long> &tab, int curr = 1){
  if(n==0){ 
    return 1;
  }
  if(tab[n]!=0) return tab[n];
  long long ways = 0;
  for(int i = 1; i<=6; i++){
    if(n-i>=0)
      ways += solve(n-i,tab)%1000000007;
  }
  tab[n] = ways;
  return tab[n];
}
int main(){
  long long n,ways = 0;
  int div = 1000000007;
  cin >> n;
  vector<long long> tab(n+1,0);
  ways = solve(n,tab);
  cout << ways%div << "\n";

  return 0;
}