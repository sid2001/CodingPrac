#include "myVariables.h"

Node createNode(int data) {
  Node node;
  node.data = static_cast<double>(data);

  return node;
}

/**
 * Creates a binary node with the given data.
 * @param data an integer representing the data for the binary node
 * @return a BinaryNode with the specified data and null left and right children
 * @throws None
 */
BinaryNode createBinaryNode(int data) {
  BinaryNode node;
  node.data = static_cast<double>(data);
  node.left = nullptr;
  node.right = nullptr;
  node.parent = nullptr;
  return node;
}

/**
 * Deletes the given node and sets its pointer to null.
 * @param node pointer to the node to be deleted
 * @return void
 * @throws None
 */
void deleteNode(Node *node){
  delete node;
  node = nullptr;//this ensures that any dangling pointers are cleared
}

void deleteBinaryNode(BinaryNode *node){
  delete node;
  node = nullptr;
}

/**
 * Find a node with the given data in a binary tree.
 *
 * @param root The root of the binary tree
 * @param data The data to search for
 *
 * @return BinaryNode* The node containing the data if found, otherwise nullptr
 *
 * @throws None
 */
BinaryNode* findNode(BinaryNode* root, int data){
  if(root == nullptr){
    return nullptr;
  }
  else if(root->data == data){
    return root;
  }
  else if(root->data > data){
    return findNode(root->left, data);
  }
  else{
    return findNode(root->right, data);
  }
}

RootNode* createBinarySearchTree(auto data) {
  RootNode root = (RootNode)createBinaryNode(data);
  root.parent = &root;
  return &root;
}
