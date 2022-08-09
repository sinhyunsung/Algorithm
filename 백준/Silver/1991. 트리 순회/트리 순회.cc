#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

struct tree {
	string key;
	tree* left;
	tree* right;
};

tree* root;

void insert(tree* node, string a, string b, string c) {
	if (node->key == a) {
		if (b != ".") {
			tree* leftnode=new tree;
			leftnode->key = b;
			leftnode->left = nullptr;
			leftnode->right = nullptr;
			node->left = leftnode;
		}
		if (c != ".") {
			tree* rightnode = new tree;
			rightnode->key = c;
			rightnode->left = nullptr;
			rightnode->right = nullptr;
			node->right = rightnode;
		}
	}
	else
	{
		if (node->left!=nullptr) {
			insert(node->left, a, b, c);
		}
		if (node->right!= nullptr) {
			insert(node->right, a, b, c);
		}

	}
}


void preorder(tree* node) {
	cout << node->key;
	if (node->left != nullptr) {
		preorder(node->left);
	}
	if (node->right != nullptr) {
		preorder(node->right);
	}
}
void inorder(tree* node) {

	if (node->left != nullptr) {
		inorder(node->left);
	}
	cout << node->key;
	if (node->right != nullptr) {
		inorder(node->right);
	}
}
void postorder(tree* node) {

	if (node->left != nullptr) {
		postorder(node->left);
	}
	if (node->right != nullptr) {
		postorder(node->right);
	}
	cout << node->key;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	string a, b, c;
	root = new tree;
	root->key = "A";
	root->left = nullptr;
	root->right = nullptr;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		insert(root, a, b, c);
	}
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);

}
