// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=196&mosmsg=Submission+received+with+ID+28710257
#include <bits/stdc++.h>

using namespace std;

int bwon = 0;
int mx[] = {-1,-1,0,0,1,1};
int my[] = {-1,0,-1,1,0,1};

// void dfs(vector<vector<char>> &vec, int x,int y,int dim){
    
//     // if(x>-1&&x<dim&&y>-1&&y<dim&&vec[x][y]=='b'){
//     //     if(x==dim-1){
            
//     //         bwon = 1;
//     //         return;
//     //     }
//     // }
//     queue<pair<int,int>> q;
//     q.push(make_pair(x,y));
    
//     while(!q.empty()){
        
//         int cx = q.front().first;
//         int cy = q.front().second;
//         q.pop();
//         vec[cx][cy] = '0';
        
//         for(int i =0;i<6;i++){
            
//             int nx = cx + mx[i];
//             int ny = cy + my[i];
//             if(nx>-1&&nx<dim&&ny>-1&&ny<dim&&(vec[nx][ny]=='b'||vec[nx][ny]=='v')){
//                 if(nx==dim-1){
//                     bwon = 1;
//                     return;
//                 }
//                 if(vec[nx][ny]!='v')
//                     q.push(make_pair(nx,ny));
//                 vec[nx][ny]='v';
//             }    
//         }
//     }
// }
void DFS(vector<vector<char>> &vec,int u, int v,int dim) {
    if (!bwon && u>=0 && u<dim && v>=0 && v<dim && vec[u][v]=='b') {
        if (u==dim-1) {
            bwon=1; return;
        }
        vec[u][v]='0';
        DFS(vec,u-1,v-1,dim); DFS(vec,u-1,v,dim);
        DFS(vec,u,v-1,dim); DFS(vec,u,v+1,dim);
        DFS(vec,u+1,v,dim); DFS(vec,u+1,v+1,dim);
    }
}

int main(){
    
    int n;
    int games = 0;
    int dim;
    while(cin>>dim&&dim){
        
        cin.get();
        int di = dim;
        int di2 = dim;
        // cout<<dim<<endl;
        string s;
        int row=0;
        int col = 0;
        vector<vector<char>> vec(dim,vector<char>(dim,'0'));
        while(dim--){
          
          getline(cin,s);
        //   stringstream ss(s);
        //   while(di2--){
          
        //   ss>>vec[row][col];
        //   cout<<vec[row][col++];
        //   cout<<s<<endl;
          for(int i =0;i<di2;i++){
              vec[row][col++] =s[i] ;
          }
          col= 0;
          row++;
        }
        
        // if(dim==0) break;
        
        // for(int i =0;i<di;i++){
            
        //     for(int j = 0;j<di;j++){
                
                
        //         cout<<vec[i][j];
        //     }
        //     cout<<endl;
        // }
        
        for(int i =0;i<di;i++){
            
            if(vec[0][i]!='0'&&vec[0][i]=='b')
                DFS(vec,0,i,di);
                // dfs(vec,0,i,di);
            if(bwon==1){
                break;
            }
        }
        if(bwon) cout<<(++games)<<" "<<'B'<<endl;
        else cout<<(++games)<<" "<<'W'<<endl;
        bwon = 0;
    }
}