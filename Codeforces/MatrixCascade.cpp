#include <bits/stdc++.h>

using namespace std;

// void display(vector<vector<int>> &vec,int len){

//   for(int i =0;i<len;i++){

//     for(int j=0;j<len;j++){
//       cout<<vec[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<"===="<<endl;
// }

int main(){
    
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);

  int t;
  cin>>t;
  while(t--){

    int len;
    cin>>len;
    int n = len;
    
    vector<vector<int>> vec(len,vector<int>(len,0));
    for(int i = 0;i<len;i++){
      for(int j = 0;j<len;j++){
        char x;
        cin>>x;
        vec[i][j]=(int)x -'0';
      }
    }
    int ans = 0;
    vector<vector<int>> check(len,vector<int>(len,0));
    vector<vector<int>> uncheck(len,vector<int>(len,0));

    for(int i =1;i<=n;i++){
      int count = 0;
    //   display(vec,len);
      for(int j = 1;j<=n;j++){
        
        if(i>1&&j<=n-2){

          if(j>=1&&check[i-2][j])
            check[i-1][j-1]+=check[i-2][j];
          if(j==1){
            check[i-1][j-1] += check[i-2][0];
          }
        }
        if(j<=n&&i>1){
          if(uncheck[i-2][j-2]) uncheck[i-1][j-1]+=uncheck[i-2][j-2];
        }
        count += check[i-1][j-1] + uncheck[i-1][j-1];
        if(count%2!=0){
          vec[i-1][j-1] = vec[i-1][j-1]==0?1:0;
        }
        

        int value = vec[i-1][j-1];
        
        if(i==1) {
          vec[i-1][j-1] = 0;
          
        }
        
        if(value){
          if(i<n){
            if(j>1)
              check[i][j-2]++;
            else
              check[i][0]++;
            if(j<n-1)
              uncheck[i][j+1]--;
          
          }
          vec[i-1][j-1] = 0;
          ans++;
          // int wid = 1;
          // for(int k = i+1;k<=n;k++){
          //   int diff = abs(i-j)+abs(k-i);
          //   int low = j - wid;
          //   int high = j + wid;
          //   if(low-1>=0) check[k-1][low-1]++;
          //   else check[k-1][0]++;
          //   if(high-1<len-1) check[k-1][high]--;
          //   wid++;
          // }
          
        }
        
        
      }
    //   display(check,len);
    //   display(uncheck,len);
    //   cout<<"-----"<<endl;
    //   display(vec,len);      
    }
    cout<<ans<<endl;
  }
}