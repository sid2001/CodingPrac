#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int x,y;
    cin>>x>>y;
    vector<vector<char>> vec(x,vector<char>(y));
    for(int i=0;i<x;i++){
      string jj;
      cin>>jj;
      for(int j = 0;j<y;j++){
        vec[i][j] = jj[j];
      }
    }
    string name = "vika";
    string st = "";
    int indx = 0;
    int found = 0;
    for(int i=0;i<y;i++){
      for(int j = 0;j<x;j++){
        if(vec[j][i]==name[indx]){
          st += vec[j][i];
          indx++;
          if(indx==4){found = 1; break;}
          break;
        }
      }
      if(found) break;
    }
    if(found)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}