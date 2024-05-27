#include<iostream>
#include<vector>
#include<cmath>

using namespace std;



void display(vector<int> &marked,int maxi){
  int i = 0;
  cout<<31<<"\n";
  while(i<31){
    cout<<(marked[i]==-2?0:marked[i])<<" ";
    i++;
  }
  cout<<"\n";
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
    marked[indx+1] = sign;
    maxi = max(indx+1,maxi);
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