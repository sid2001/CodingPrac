#include <iostream>
#include <vector>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	int val;
	vector<int> indx;
	int l;
	int r;
	Node(int val,int l,int r): val(val), l(l), r(r) {}
	Node(int l , int r): l(l), r(r) {}
};

Node* build(vector<int> &vec, int l, int r) {
	if(l == r) {
		Node* node = new Node(vec[l],l,l,l);
		(node->indx).push_back(l);
		return node;
	}
	Node* node = new Node(l,r);
	int m = (l + r) / 2;
	node->left = build(vec, l,m);
	node->right = build(vec, m+1, r);
	if(node->left->val > node->right->val) {
		node->val = node->left->val;
		node->indx = node->left->indx;
	}else if(node->left->val < node->right->val){
		node->val = node->right->val;
		node->indx = node->right->indx;
	}else{
		vector<int> x;
		for(auto v: node->left->indx) {
			x.push_back(v);
		}
		for(auto v: node->right->indx) {
			x.push_back(v);
		}
	}
	return node;
}

vector<int> find_max(Node* root,vector<int> &vec, int l, int r) {
	if(l == root->l && r == root->r) return root->indx;
// 	cout<<l<<" "<<r<<" "<<root->l<<" "<<root->r<<endl;
	if(l > root->left->r) {
		return find_max(root->right, vec, l, r);
	}else if(r < root->right->l) {
		return find_max(root->left, vec, l, r);
	}else {
		int left = find_max(root->left, vec, l, root->left->r);
		int right = find_max(root->right, vec, root->right->l, r);
		if(vec[left[0]] > vec[right[0]]) return left;
		else if(vec[left[0]] < vec[right[0]])return right;
		else {
			vector<int> x;
			for(auto v: left) {
				x.push_back(v);
			}
			for(auto v: right) {
				x.push_back(v);
			}
		}
	}
}

int solve(vector<int> &vec, Node* root, int l, int r,int prev = -1) {
	if(l == r) return 1;
	int left = 0, right = 0;
    // cout<<l<<" "<<r<<" "<<endl;
	vector<int> indx = find_max(root, vec, l, r);
	int p = -1;
	for(int i = 0; i < indx.size(); i++) {
		if(i == 0) {
			if(indx[i] != l) {
				left = solve(vec, root, l, indx - 1,indx);
			}
			if(indx[i] != r) {
				right = solve(vec,root, indx + 1, r,indx);
			}
		}
	}

	return max(left,right) + 1;
}

int main(){
	int n,ans = 1;
	cin>>n;
	vector<int> vec(n);
	for(int i = 0; i < n; i++) cin>>vec[i];
	Node* root = build(vec, 0, n-1);

	cout<<solve(vec, root, 0, n-1)<<"\n";
}
