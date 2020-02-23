#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	node *left, *right;
	int num, height;
}root;
int n;

node* newNode(int v) {
	node* Node = new node;
	Node->num = v;
	Node->height = 1;
	Node->left = Node->right = NULL;
	return Node;
}
int getHeight(node* &root) {
	if (root == NULL) return 0;
	else return root->height;
}
void update(node* &root) {
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalance(node* &root) {
	return getHeight(root->left) - getHeight(root->right);
}
void R(node* &root) {// ÓÒÐý
	node* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	update(root);
	update(tmp);
	root = tmp;
}
void L(node* &root) {// ×óÐý
	node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	update(root);
	update(tmp);
	root = tmp;

}
void insert(node* &root, int v) {
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (v < root->num) {
		insert(root->left, v);
		update(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->left) == 1)
				R(root);
			else if (getBalance(root->left) == -1) {
				L(root->left);
				R(root);
			}
		}
	}
	else {
		insert(root->right, v);
		update(root);
		if (getBalance(root) == -2) {
			if (getBalance(root->right) == -1)
				L(root);
			else if (getBalance(root->right) == 1) {
				R(root->right);
				L(root);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("ouput.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	cin >> n;
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		insert(root, a);
	}
	cout << root->num << endl;
	return 0;
}