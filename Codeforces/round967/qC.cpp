#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &vec) {
  cout<<"! ";
  for(int i = 2; i < vec.size(); i++) {
    cout<<i<<" "<<vec[i]<<" ";
  }
  cout<<endl;
  cout.flush();
  return;
}

void findParent(vector<int> &p, int a, int b) {
  cout<<"?"<<" "<<a<<" "<<b<<"\n";
  cout<<endl;
  cout.flush();
  int x;
  cin>>x;
  if(a == x) {
    p[a] = b;
    return;
  }
  findParent(p,a,x);
  if(p[x] == -1)
    findParent(p,x,b);
  return;
}

void solve() {
  int nodes;
  cin>>nodes;
  vector<int> p(nodes + 1, -1);
  int root = 1;
  for(int i = 2; i<= nodes; i++) {
    if(p[i] == -1) {
      findParent(p, i, root);
    }
  }
  display(p);
  return;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}