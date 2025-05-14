#include <vector>
struct BinaryNode{
  double data;
  BinaryNode* parent;
  BinaryNode* left;
  BinaryNode* right;
};
struct Node{
  double data;
  std::vector<Node*> children;
};

typedef BinaryNode RootNode;