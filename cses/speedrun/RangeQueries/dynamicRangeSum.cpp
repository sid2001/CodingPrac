#include<iostream>
#include <vector>

using namespace std;

struct Node {
  long long rsum;
  int low;
  int high;
  Node* rchild;
  Node* lchild;
};

Node* createNode(int low, int high) {
  Node* node = new Node();
  node->low = low;
  node->high = high;
  return node;
}
Node* createTree(vector<long long> &vec, int low, int high) {
  Node* node  = createNode(low,high);
  int mid = (low + high)/2;
  if(low<high) {
    node->lchild = createTree(vec, low, mid);
    node->rchild = createTree(vec,mid+1,high);
    node->rsum = node->lchild->rsum + node->rchild->rsum;
  }else if(low==high) {
    node->rsum = vec[low];
  }
  return node;
}

void updateTree(Node* node, int k, long long u,long long diff) {
  int mid = (node->low + node->high)/2;
  node->rsum += diff;
  if(node->low==node->high) {
   // node->rsum = u;
    return;
  }
  if(k<=mid) {
    updateTree(node->lchild,k,u,diff);
  }else if(k>mid) {
    updateTree(node->rchild,k,u,diff);
  }
  return;
}

long long querySum(Node* node, int a, int b) {
  int mid = (node->low + node->high)/2;
  if(a==node->low && b==node->high) {
    return node->rsum;
  }
  if(a>mid) {
    return querySum(node->rchild,a,b);
  }else if(b<=mid) {
    return querySum(node->lchild,a,b);
  } else {
    return querySum(node->lchild,a,mid) + querySum(node->rchild,mid+1,b);
  }
}

void solve(Node* node,vector<long long> &vec) {
  int x,a,b;
  cin>>x>>a>>b;

  if(x==1) {
    updateTree(node, a-1, b, b - vec[a-1]);
    vec[a-1] = b;
  }else if(x==2){
    cout<<querySum(node, a-1, b-1)<<"\n";
  }
}

int main() {
  int n,q;
  cin>>n>>q;
  vector<long long> vec(n);
  for(int i = 0; i<n; i++) {
    cin>>vec[i];
  }
  Node* root = createTree(vec, 0, n-1);
  while(q--) {
    solve(root,vec);
  }

}