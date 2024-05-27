#include<iostream>
#include<vector>
#include<cmath>
 
using namespace std;
 
void getValue(vector<int> &marked){
  int sum = 0;
  for(int i = 0;i<31;i++){
    if(marked[i]!=-2){
      sum += pow(2,i)*marked[i];
    }
  }
  cout<<sum<<"\n";
}
 
void display(vector<int> &marked,int maxi){
  int i = 0;
  cout<<31<<"\n";
  while(i<31){
    cout<<(marked[i]==-2?0:marked[i])<<" ";
    i++;
  }
  cout<<"\n";
  // getValue(marked);
  return;
}
void solve(vector<int> &marked,int n, int &flag,int maxi = 0){
  if(flag == 1) return;
  if(n==0){
    display(marked,maxi);
    flag = 1;
    return;
  }
 
  int sign = (int)(abs(n)/n);
  int indx = (int)(log(abs(n))/log(2));
  
  if((indx > 0 && marked[indx-1] != -2) || marked[indx+1] != -2||marked[indx] != -2){
    return;
  }else{
    n -= sign*pow(2,indx);
    marked[indx] = sign;
    maxi = max(indx,maxi);
    solve(marked,n,flag,maxi);
    if(flag == 1) return;
 
    n += sign*pow(2,indx);
    marked[indx] = -2;
    n -= sign*pow(2,indx+1);
    indx = indx + 1;
    if((indx > 0 && marked[indx-1] != -2) ||(indx < 30 && marked[indx+1] != -2)){
      return;
    }
    marked[indx] = sign;
    maxi = max(indx,maxi);
    solve(marked,n,flag,maxi);
  }
  return;
}
 
 
int main(){
  int t;
  cin>>t;
  int flag = 0;
  while(t--){
    flag = 0;
    int n;
    cin>>n;
    vector<int> marked(31,-2);
    solve(marked,n,flag);
  }
  return 0;
}