// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1277

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<char>> &vec, int x,int y,char ch,int limx,int limy){
    
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        vec[cx][cy] = '0';
        q.pop();
        
        for(int i = 0;i<4;i++){
            
            if(cx+dx[i]<limx&&cx+dx[i]>=0&&cy+dy[i]<limy&&cy+dy[i]>=0&&vec[cx+dx[i]][cy+dy[i]]!='0'&&vec[cx+dx[i]][cy+dy[i]]==ch)
                q.push(make_pair(cx+dx[i],cy+dy[i]));
        }
        
    }
    
}

bool cmp(pair<int, int> a, pair<int, int> b){
    
    if( a.second>b.second)
        return a.second>b.second;
    else if(a.second==b.second){
        return a.first<b.first;
    }
    else
        return a.second>b.second;
}

int main(){
    
    int t;
    cin>>t;
    int world = 0;
    while(t--){
        
        int x,y;
        cin>>x>>y;
        vector<vector<char>> vec(x,vector<char>(y,'0'));
        
        for(int i=0;i<x;i++){
            
            for(int j = 0;j<y;j++){
                
                
                char ch;
                cin>>ch;
                vec[i][j] = ch;
            }
        }
        vector<pair<int,int>> ct(26,pair<int,int>(0,0));
        for(int i=0;i<x;i++){
            
            for(int j = 0;j<y;j++){
                
                if(vec[i][j]!='0'){
                    ct[vec[i][j]-'a'].first = vec[i][j]-'a';
                    ct[vec[i][j]-'a'].second++;
                    dfs(vec,i,j,vec[i][j],x,y);
                }
            }
        }
        sort(ct.begin(),ct.end(),cmp);
        cout<<"World #"<<(++world)<<endl;
        for(auto a:ct){
            if(a.second==0) break;
            cout<<char(a.first+97)<<": "<<a.second<<endl;
        }
    }
}