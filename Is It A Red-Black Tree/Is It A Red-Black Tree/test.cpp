#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;
int k;
struct  node{
	int num,red;
	node *left, *right;
	node() {
		left = right = NULL;
	}
	void set(int val) {
		if (val < 0)red = 1;
		else red = 0;
		num = abs(val);
	}
};

void build(node* &root,int num) {
	if (root == NULL) { // ½¨Ê÷
		root = new node();
		root->set(num);
		return;
	}
	if (abs(num) > root->num)
		build(root->right, num);
	else build(root->left, num);
}
int last = -1;
bool tag = true;
void dfs(node *n,int cou) {
	if (!tag) return;
	if (n == NULL) {
		if (last == -1) last = cou;
		else if (last != cou) tag = false;
		return;
	}
	if (!n->red) ++cou;
	else{
		if (n->left && n->left->red) tag = false;
		if (n->right && n->right->red) tag = false;
	}
	dfs(n->left, cou);
	dfs(n->right, cou);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,a;
	cin >> k;
	while (k--) {
		cin >> n;
		node *root = NULL;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a < 0) {
				build(root, a);
			}else{
				build(root, a);
			}
		}
		last = -1;
		tag = true;
		dfs(root, 0);
		if (root->red) tag = false;
		if (tag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}