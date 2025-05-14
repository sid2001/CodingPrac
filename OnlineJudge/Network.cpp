#include <bits/stdc++.h>

using namespace std;

// struct Node{
//   vector<Node*> friends;
//   int critical = 0;
//   int visited = 0;
//   int friendCount = 0;
// }*nodes[100];

// void newNode(int pos){

//   struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//   nodes[pos] = node;
// }
// void addFriend(struct Node* frnd,struct Node* node){

//   node->friends.push_back(frnd);
//   node->friendCount++;
//   frnd->friends.push_back(node);
//   frnd->friendCount++;
// }

void DFS(vector<int> adj[],int curr,int critical[],int low[],int inse[],int time,int parent,int visited[]){

  visited[curr] = 1;
  low[curr] = inse[curr] = time;
  time++;
  int child = 0;
  for(auto i: adj[curr]){
    if(i==parent) continue;
    else if(visited[i]) {
      low[curr] = min(low[curr],inse[i]);
    }
    else{
      DFS(adj,i,root,critical,low,inse,time,curr,visited);
      low[curr] = min(low[i],low[curr]);
      if(low[i]>=inse[curr]&&parent!=-1)
          critical[curr] = 1;
    }
    child++;
  }
  if(parent==-1&&child>1)
    critical[curr] = 1;
}

int main(){

  int n;
  while(cin>>n&&n){
    vector<int> adj[n];
    int critical[n] = {0};
    int low[n] = {-1};
    int inse[n] = {-1};
    int visited[n] = {0};
    int time = 1;
    cin.get();
    string s;
    getline(cin,s);
    while(s[0]!='0'){

      stringstream ss(s);
      int k;ss>>k;
      // cout<<k;
      int j;
      while(ss>>j){
        adj[k-1].push_back(j-1);
        adj[j-1].push_back(k-1);
        // cout<<j;
      }
      getline(cin,s);
    }
    for(int i = 0;i<n;i++){
      if(!visited[i])
        DFS(adj,i,critical,low,inse,time,-1,visited);
    }
    int count=0;
    for(auto i : critical){
      if(i==1) count++;
    }
    cout<<count<<endl;
  }
}