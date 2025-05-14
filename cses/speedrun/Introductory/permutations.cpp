#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &vec){
  for(auto i:vec){
    cout<<i<<" ";
  }
  cout<<endl;
  return;
}
void swap(vector<int> &vec){
  if(vec[0]+1!=vec[vec.size()-2]){
    int i = vec[vec.size()-1];
    vec[vec.size()-1] = vec[0];
    vec[0] = i;
  }else{
    int i = vec[vec.size()-2];
    vec[vec.size()-2] = vec[0];
    vec[0] = i;
  }
  
  return;
}
void solve(int n){
  vector<int> vec(n,0);
  int ini = 1,fin = n;
  int i = 0;
  if(n==1){
    cout<<1<<endl;
    return;
  }
  if(n<=3){
    cout<<"NO SOLUTION"<<endl;
    return;
  }
  while(ini<=fin){
    if(ini==fin){
      vec[i++] = ini;
      ini++;
      fin--;
    }else{
      vec[i++] = ini;
      vec[i++] = fin;
      ini++;
      fin--;
    }
  }
  swap(vec);
  display(vec);
}

int main(){
  int n;
  cin>>n;
  solve(n);
}