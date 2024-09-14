#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int minVal;
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
Node* createTree(vector<int> &vec, int low, int high) {
  Node* node  = createNode(low,high);
  int mid = (low + high)/2;
  if(low<high) {
    node->lchild = createTree(vec, low, mid);
    node->rchild = createTree(vec,mid+1,high);
    node->minVal = min(node->lchild->minVal, node->rchild->minVal);
  }else if(low==high) {
    node->minVal = vec[low];
  }
  return node;
}

int queryMin(Node* node, int low, int high) {
  int mid = (node->low + node->high)/ 2;
  if(low==node->low && node->high==high ) return node->minVal;
  if(mid<low){
    return queryMin(node->rchild,low,high);
  } else if(high<=mid) {
    return queryMin(node->lchild,low,high);
  } else {
    return min(queryMin(node->lchild,low,mid), queryMin(node->rchild,mid+1,high));
  }
}

int main() {
  int n, q;
  cin>>n>>q;
  vector<int> vec(n);
  for(int i = 0; i<n; i++) {
    cin>>vec[i];
  }
  Node* root = createTree(vec, 0, n-1);
  for(int i = 0; i < q;i++) {
    int a,b;
    cin>>a>>b;
    cout<<queryMin(root,a,b)<<"\n";
  }
}